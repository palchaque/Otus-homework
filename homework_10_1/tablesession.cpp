#include "tablesession.h"


void tableSession::start()
{
    read();
}

table& tableSession::detectTable(std::string tableName)
{
    if(tableName == "A") return tableA;
    if(tableName == "B") return tableB;

}

void tableSession::read()
{
    auto self(shared_from_this());
    socket.async_read_some(boost::asio::buffer(data, max_length),
    [this, self](boost::system::error_code ec, std::size_t length)
    {
        if (!ec)
        {
            const std::string input{data, length};
            static const boost::regex insertExpression("^INSERT\\s(A|B)\\s(\\d+)\\s(\\w+)\\n");
            static const boost::regex truncateExpression("^TRUNCATE (A|B)\\n");
            boost::smatch insertSearch;
            if(boost::regex_match(input, insertExpression))
            {
                boost::smatch insertSearchMatch;
                boost::regex_search(input, insertSearchMatch, insertExpression);
                table & queryTable = detectTable(insertSearchMatch[1].str());
                int id = std::stoi(insertSearchMatch[2].str());
                std::string name = insertSearchMatch[3].str();
                int queryResponse = queryTable.insertIntoTable(id, name);
                if(queryResponse == -1)
                {
                    write("OK");
                }
                else
                {
                    write("ERR duplicate "+std::to_string(queryResponse));
                }
            }
            if(boost::regex_match(input, truncateExpression))
            {
                boost::smatch truncateSearchMatch;
                boost::regex_search(input, truncateSearchMatch, truncateExpression);
                table & queryTable = detectTable(truncateSearchMatch[1].str());
                queryTable.truncateTable();
                write("OK");
            }
            if(input == "INTERSECTION\n")
            {
                write(std::move(tableA.getIntersectionTable(tableB)));
            }
            if(input == "SYMMETRIC_DIFFERENCE\n")
            {
                write(std::move(tableA.getSymmetricDifferenceTable(tableB)));
            }

        }

    });
}

void tableSession::write(std::string message)
{
    auto self(shared_from_this());
    boost::asio::async_write(socket, boost::asio::buffer(message),
        [this, self](boost::system::error_code ec, std::size_t)
        {
          if (!ec)
          {
            read();
          }
    });
}

void tableSession::write(joinedTablesOutput tables)
{
    auto self(shared_from_this());
    std::string message;
    for (auto tableRow: tables)
    {
        message+=std::to_string(tableRow.first)+","+tableRow.second.first+","+tableRow.second.second+"\n";
    }
    boost::asio::async_write(socket, boost::asio::buffer(message),
        [this, self](boost::system::error_code ec, std::size_t)
        {
          if (!ec)
          {
            read();
          }
    });
}
