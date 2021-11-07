#include "commandsserver.h"

commandsServer::commandsServer(boost::asio::io_context& io_context, short port, size_t bulk)
    : acceptor(io_context, btcp::endpoint(btcp::v4(), port)), bulkSize(bulk)
{
    do_accept();
}

void commandsServer::do_accept()
{
    acceptor.async_accept(
    [this](boost::system::error_code ec, btcp::socket socket)
    {
    if (!ec)
    {
        std::make_shared<commandSession>(std::move(socket), bulkSize)->start(commandsQueue);
        if(commandsQueue.size() >= bulkSize)
        {
            commandsOutput::printCommands(commandsQueue);
            commandsOutput::saveToFile(commandsQueue);
        }
    }
    do_accept();
    });
}


