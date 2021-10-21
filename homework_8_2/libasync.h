#ifndef LIBASYNC_H
#define LIBASYNC_H

#include "otus_82_global.h"
#include <iostream>
#include <future>
#include <thread>
#include <queue>
#include <string>
#include <memory>
#include <mutex>

struct handler
{
    size_t bulkSize;
    std::queue<std::string> commandsQueue;
    handler(){};
    static std::string getStringFromQueue(handler*);
    static void getPrintedElements(handler*, const char*, size_t);
    mutable std::mutex handlerAppendMutex;
};

class ASYNC_EXPORT libasync
{
public:
    libasync();
    static handler* connect(size_t);
    static void receive(handler*, const char *data, std::size_t size);
    static void disconnect(handler* handle);

};

#endif // LIBASYNC_H
