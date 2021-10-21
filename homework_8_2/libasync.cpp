#include "libasync.h"

void handler::getPrintedElements(handler *h, const char *data, size_t size)
{
    const std::string input{data};

    std::lock_guard<std::mutex> lock(h->handlerAppendMutex);

    for(auto i : input)
    {
        if(i == '\n' || i == '\0') continue;

        if(i == '{')
        {
            while(!h->commandsQueue.empty())
            {
                std::cout<<" ";
                std::cout<<h->commandsQueue.front();
                h->commandsQueue.pop();
            }
            continue;
        }

        if(i == '}')
        {
            while(!h->commandsQueue.empty())
            {
                std::cout<<" ";
                std::cout<<h->commandsQueue.front();
                h->commandsQueue.pop();
            }
            continue;
        }

        h->commandsQueue.emplace(std::string{i});

        if(h->commandsQueue.size() == h->bulkSize)
        {
            while(!h->commandsQueue.empty())
            {
                std::cout<<" ";
                std::cout<<h->commandsQueue.front();
                h->commandsQueue.pop();
            }

        }

    }

}

std::string handler::getStringFromQueue(handler *h)
{
    std::string output;

    std::lock_guard<std::mutex> lock(h->handlerAppendMutex);

    while(!h->commandsQueue.empty())
    {
        output.append(" ");
        output.append(h->commandsQueue.front());
        h->commandsQueue.pop();
    }

    return output;
}

libasync::libasync()
{

}

handler* libasync::connect(size_t bulkSize)
{

    std::shared_ptr<handler> h = std::make_shared<handler>();
    h->bulkSize = bulkSize;
    return h.get();

}

void libasync::receive(handler *h, const char *data, std::size_t size)
{

    auto futureResult = std::async(std::launch::async, handler::getPrintedElements, h, data, size);

}

void libasync::disconnect(handler * h)
{

    if(!h->commandsQueue.empty())
    {
        std::cout<<handler::getStringFromQueue(h)<<std::endl;
    }    

}
