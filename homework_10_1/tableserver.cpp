#include "tableserver.h"

tableServer::tableServer(boost::asio::io_context& io_context, short port):acceptor(io_context, btcp::endpoint(btcp::v4(), port))
{
    do_accept();
}

void tableServer::do_accept()
{
    acceptor.async_accept(
    [this](boost::system::error_code ec, btcp::socket socket)
    {
    if (!ec)
    {
        std::make_shared<tableSession>(std::move(socket), tableA, tableB)->start();
    }
    do_accept();
    });
}
