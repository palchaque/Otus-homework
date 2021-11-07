#ifndef TABLESESSION_H
#define TABLESESSION_H

#include <boost/asio.hpp>
#include <boost/regex.hpp>
#include <memory>
#include <iostream>

#include "table.h"

using btcp = boost::asio::ip::tcp;

class tableSession: public std::enable_shared_from_this<tableSession>
{
public:
    tableSession(btcp::socket s, table &tA, table &tB): socket(std::move(s)), tableA(tA), tableB(tB) {};
    void start();
private:
    btcp::socket socket;
    void read();
    void write(std::string message);
    void write(joinedTablesOutput);
    table& detectTable(std::string);
    enum { max_length = 1024 };
    char data[max_length];
    table &tableA;
    table &tableB;
};

#endif // TABLESESSION_H
