#ifndef TABLESERVER_H
#define TABLESERVER_H

#include <boost/asio.hpp>

#include "table.h"
#include "tablesession.h"

using btcp = boost::asio::ip::tcp;

class tableServer
{
public:
    tableServer(boost::asio::io_context& io_context, short port);

private:
    table tableA;
    table tableB;
    btcp::acceptor acceptor;
    void do_accept();

};

#endif // TABLESERVER_H
