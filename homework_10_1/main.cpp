#include <iostream>
#include <string>

#include "table.h"
#include "tableserver.h"


int main(int argc, char* argv[])
{    
    try
    {
      if (argc < 2)
      {
        std::cout << "Port not set\n";
        return 1;
      }
      boost::asio::io_context io_context;

      tableServer server(io_context, std::atoi(argv[1]));

      io_context.run();
    }
    catch (const std::exception& ex)
    {
      std::cerr << "Exception: " << ex.what() << "\n";
    }

    return 0;
}
