#include "lib.h"

#include <iostream>

int main (int, char **)
{
    std::cout << "Hello world" << std::endl;
    std::cout << "Version: " << version() << std::endl;

    return 0;
}
