#ifndef COMMANDSESSION_H
#define COMMANDSESSION_H

#include <queue>
#include <string>
#include <memory>
#include <boost/asio.hpp>
#include <iostream>

#include "commandsoutput.h"

using btcp = boost::asio::ip::tcp;
class commandSession: public std::enable_shared_from_this<commandSession>
{
public:
    commandSession(btcp::socket s, int bs)
        : socket(std::move(s)), bulkSize(bs){};
    void start(std::queue<std::string> &serverCommands);
private:
    void read(std::queue<std::string> &serverCommands);
    btcp::socket socket;
    std::queue<std::string> innerBlockData;
    enum { max_length = 1024 };
    char data[max_length];
    int bulkSize;
};

#endif // COMMANDSESSION_H
