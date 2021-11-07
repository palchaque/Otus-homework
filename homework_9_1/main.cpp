#include <iostream>
#include <memory>
#include <utility>
#include <boost/asio.hpp>

#include "commandsserver.h"

int main(int argc, char* argv[])
{
    try
    {
      if (argc < 2)
      {
        std::cout << "Port not set\n";
        return 1;
      }

      if(argc < 3)
      {
        std::cout << "Bulk size not set\n";
        return 1;
      }

      boost::asio::io_context io_context;

      commandsServer server(io_context, std::atoi(argv[1]), std::atoi(argv[2]));

      io_context.run();
    }
    catch (const std::exception& ex)
    {
      std::cerr << "Exception: " << ex.what() << "\n";
    }

    return 0;
}
