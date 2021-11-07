#include "commandsession.h"

void commandSession::start(std::queue<std::string> &serverCommands)
{
    read(serverCommands);
}

void commandSession::read(std::queue<std::string> &serverCommands)
{
    auto self(shared_from_this());
    socket.async_read_some(boost::asio::buffer(data, max_length),
    [this, self, &serverCommands](boost::system::error_code ec, std::size_t length)
    {
        if (!ec)
        {            
            const std::string output{data, length};
            bool innerBlockInitialized = false;
            for (auto s: output)
            {
                if(s == ' ' || s == '\n') continue;

                if(s == '{')
                {
                    innerBlockInitialized = true;
                    return;
                }

                if(s == '}')
                {
                    innerBlockInitialized = false;
                    return;
                }

                if(innerBlockInitialized)
                    innerBlockData.emplace(&s);
                else
                    serverCommands.emplace(&s);
            }

            if(innerBlockData.size() >= bulkSize)
            {
                commandsOutput::printCommands(innerBlockData);
                commandsOutput::saveToFile(innerBlockData);
            }
        }
    });
}
