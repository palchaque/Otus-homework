#ifndef COMMANDSOUTPUT_H
#define COMMANDSOUTPUT_H

#include <iostream>
#include <queue>
#include <string>
#include <ctime>
#include <fstream>

class commandsOutput
{
public:
    commandsOutput();
    static void printCommands(std::queue<std::string> &commands);
    static void saveToFile(std::queue<std::string> &commands);
};

#endif // COMMANDSOUTPUT_H
