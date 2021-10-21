#include "bulkcommandprinter.h"

bulkCommandPrinter::bulkCommandPrinter()
{

}

std::string bulkCommandPrinter::getOutputString(const tBulk &bulk)
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

void bulkCommandPrinter::print(const int bulkSize)
{
    std::string input = "";

    bool isDynamicBlock;

    int dynamicBlockCounter = 0;

    while(std::getline(std::cin, input))
    {
        if(fileName.empty() && !input.empty()) fileName = std::to_string(std::time(0))+".log";

        if (!isDynamicBlock)
        {
            isDynamicBlock = input == "{";

            if(isDynamicBlock)
            {
                if (dynamicBlockCounter == 0 && !bulk.empty())
                {
                    std::cout<<getOutputString(bulk)<<std::endl;
                    bulk.clear();
                }
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
            if(dynamicBlockCounter == 0)
            {
                std::cout<<getOutputString(bulk)<<std::endl;
                bulk.clear();
            }
            continue;
        }

        bulk.emplace(input);
        commandsQueue.emplace(input);

        if (bulk.size() == bulkSize && !isDynamicBlock && dynamicBlockCounter==0)
        {
            std::cout<<getOutputString(bulk)<<std::endl;
            bulk.clear();
        }

    }

    runFileSavingThreads = false;

}


void bulkCommandPrinter::saveToFile()
{

    while (runFileSavingThreads) {

        if(fileName.empty()) continue;
        const std::lock_guard<std::mutex> lock(fileSaveMutex);
        if (!commandsQueue.empty())
        {
            std::ofstream  outputFile;
            outputFile.open(fileName, std::ios_base::app);
            if(fs::is_empty(fs::path(fileName)))
            {
                outputFile<<"bulk: ";
            }
            outputFile<<commandsQueue.front()+", ";
            outputFile.close();
            commandsQueue.pop();

            //std::cout<<std::this_thread::get_id()<<std::endl;

        }
    }

}

void bulkCommandPrinter::start(const int bulkSize)
{
    if(bulkSize == 0)
    {
        std::cout<<"Bulk size was not set"<<std::endl;
        return;
    }

    file1 = std::thread(&bulkCommandPrinter::saveToFile, this);
    file2 = std::thread(&bulkCommandPrinter::saveToFile, this);
    file1.detach();
    file2.detach();

    log = std::thread(&bulkCommandPrinter::print, this, bulkSize);
    log.join();

    runFileSavingThreads = true;

}

void bulkCommandPrinter::stop()
{
    runFileSavingThreads = false;
}
