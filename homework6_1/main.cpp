#include <iostream>
#include <fstream>
#include <ctime>
#include <set>

using tBulk = std::multiset<std::string>;

std::string getOutputString(const tBulk &bulk)
{
    std::string output = "bulk: ";
    bool firstElement = true;

    for (auto bulkElement:bulk)
    {
        if (!firstElement) output+=", ";
        output+=bulkElement;
        firstElement = false;
    }

    return output;

}

void printBulk(const tBulk &bulk)
{

    std::cout<<getOutputString(bulk);

}

void saveBulkToFile(const std::string filename, const tBulk &bulk)
{
    std::ofstream  outputFile;

    outputFile.open(filename+".log");

    outputFile<<getOutputString(bulk);

    outputFile.close();
}

void printSaveBulk(std::string &cmdTime, tBulk &bulk)
{
    if(bulk.empty()) return;

    printBulk(bulk);
    saveBulkToFile(cmdTime, bulk);
    cmdTime.clear();
    bulk.clear();
}

int main(int argc, char* argv[]) {

    const int bulkSize = std::stoi(argv[1]);

    std::string input;

    tBulk bulk;
    bool isDynamicBlock;

    std::string cmdTime;

    int dynamicBlockCounter = 0;

    while(std::getline(std::cin, input))
    {
        if(cmdTime.empty()) cmdTime = std::to_string(std::time(0));

        if (!isDynamicBlock)
        {
            isDynamicBlock = input == "{";

            if(isDynamicBlock)
            {
                if (dynamicBlockCounter == 0) printSaveBulk(cmdTime, bulk);
                dynamicBlockCounter++;
                continue;
            }
        }

        if (input == "{")
        {
            dynamicBlockCounter++;
            continue;
        }

        if(input == "}" && isDynamicBlock)
        {
            dynamicBlockCounter--;
            if(dynamicBlockCounter == 0) isDynamicBlock = false;
            if(dynamicBlockCounter == 0) printSaveBulk(cmdTime, bulk);
            continue;
        }

        bulk.emplace(input);

        if (bulk.size() == bulkSize && !isDynamicBlock && dynamicBlockCounter==0)
        {
            printSaveBulk(cmdTime, bulk);
        }

    }

    if (!bulk.empty() && !isDynamicBlock) printSaveBulk(cmdTime, bulk);

    return 0;
}
