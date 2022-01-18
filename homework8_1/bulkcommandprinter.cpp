#include "bulkcommandprinter.h"

bulkCommandPrinter::bulkCommandPrinter()
{
    fileName = "";
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

void bulkCommandPrinter::printOutputString(const tBulk &bulk)
{
    std::cout<<getOutputString(bulk)<<std::endl;
}

void bulkCommandPrinter::print()
{

   printOutputString(bulk);

}


void bulkCommandPrinter::saveToFile()
{
    while (runFileSavingThreads) {

        std::unique_lock<std::mutex> lock(fileSaveMutex);

        condition.wait(lock, [this]{return !commandsQueue.empty() && !fileName.empty();});

        if(fileName.empty()) return;

        std::ofstream outputFile;
        outputFile.open(fileName, std::ios_base::app);
        if(fs::is_empty(fs::path(fileName)))
        {
            outputFile<<"bulk: ";
        }
        outputFile<<commandsQueue.front()+", ";
        outputFile.close();
        commandsQueue.pop();

        condition.notify_all();
        lock.unlock();
    }

}

void bulkCommandPrinter::parse(const int bulkSize)
{
    std::string input = "";

    bool isDynamicBlock;

    int dynamicBlockCounter = 0;

    while(std::getline(std::cin, input))
    {
        std::unique_lock<std::mutex> lock(fileSaveMutex);

        if(fileName.empty() && !input.empty()) fileName = std::to_string(std::time(0))+".log";
        condition.notify_all();

        if (!isDynamicBlock)
        {
            isDynamicBlock = input == "{";

            if(isDynamicBlock)
            {
                if (dynamicBlockCounter == 0 && !bulk.empty())
                {
                    continue;
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
                continue;
                bulk.clear();
            }
            continue;
        }

        bulk.emplace(input);
        commandsQueue.emplace(input);
        condition.notify_all();

        lock.unlock();
    }

}

void bulkCommandPrinter::start(const int bulkSize)
{
    if(bulkSize == 0)
    {
        std::cout<<"Bulk size was not set"<<std::endl;
        return;
    }

    parser = std::thread(&bulkCommandPrinter::parse, this, bulkSize);

    log = std::thread(&bulkCommandPrinter::print, this);

    file1 = std::thread(&bulkCommandPrinter::saveToFile, this);
    file2 = std::thread(&bulkCommandPrinter::saveToFile, this);

    parser.join();
    file1.join();
    file2.join();
    log.join();

    runFileSavingThreads = true;

}

void bulkCommandPrinter::stop()
{
    runFileSavingThreads = false;
}
