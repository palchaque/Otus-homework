#ifndef COMMANDSSERVER_H
#define COMMANDSSERVER_H

#include <memory>
#include <utility>
#include <boost/asio.hpp>
#include <iostream>
#include <queue>
#include <string>

#include "commandsession.h"
#include "commandsoutput.h"

using btcp = boost::asio::ip::tcp;

class commandsServer
{
public:
    commandsServer(boost::asio::io_context& io_context, short port, size_t bulkSize);

private:
    size_t bulkSize;
    btcp::acceptor acceptor;
    std::queue<std::string> commandsQueue;
    void do_accept();


};

#endif // COMMANDSSERVER_H
