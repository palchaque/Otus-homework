#include "commandsoutput.h"

commandsOutput::commandsOutput()
{

}

void commandsOutput::printCommands(std::queue<std::string> &commands)
{
    std::string outputString = "bulk: ";
    while (!commands.empty())
    {
        outputString += ", "+commands.front();
        commands.pop();
    }

    std::cout<<outputString<<std::endl;
}

void commandsOutput::saveToFile(std::queue<std::string> &commands)
{
    const std::string filename = std::to_string(std::time(0))+".log";
    std::ofstream outputFile;

    outputFile.open(filename);

    std::string outputString = "bulk: ";
    while (!commands.empty())
    {
        outputString += ", "+commands.front();
        commands.pop();
    }

    outputFile<<outputString;

    outputFile.close();
}
