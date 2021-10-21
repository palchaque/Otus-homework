#include <iostream>
#include <fstream>
#include <ctime>
#include <set>
#include <thread>

#include "bulkcommandprinter.h"

using tBulk = std::multiset<std::string>;


int main(int argc, char* argv[])
{

    if(argc < 1)
    {
        std::cout<<"Bulk size was not set"<<std::endl;
        return 1;
    }

    bulkCommandPrinter printer;
    printer.start(std::stoi(argv[1]));


    return 0;
}
