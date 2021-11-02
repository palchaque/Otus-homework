#ifndef BULKCOMMANDPRINTER_H
#define BULKCOMMANDPRINTER_H

#include <thread>
#include <mutex>
#include <iostream>
#include <fstream>
#include <fstream>
#include <ctime>
#include <queue>
#include <set>
#include <filesystem>
#include <condition_variable>

using tBulk = std::multiset<std::string>;
namespace fs = std::filesystem;

class bulkCommandPrinter
{
public:
    bulkCommandPrinter();
    void start(const int bulkSize);
    void stop();
private:
    void print(const int bulkSize);
    void saveToFile();
    void printOutputString(const tBulk&);
    std::string getOutputString(const tBulk&);
    std::thread file1;
    std::thread file2;
    std::thread log;
    std::condition_variable condition;
    std::queue<std::string> commandsQueue;
    std::string fileName;
    std::mutex fileSaveMutex;
    bool runFileSavingThreads;
    tBulk bulk;

};

#endif // BULKCOMMANDPRINTER_H
