#include "libasync.h"

int main()
{
    size_t bulk = 5;
    auto h1 = libasync::connect(bulk);
    auto h2 = libasync::connect(bulk);
    libasync::receive(h1, "1", 1);
    libasync::receive(h2, "1\n", 2);
    libasync::receive(h1, "\n2\n3\n4\n5\n6\n{\na\n", 15);
    libasync::receive(h1, "b\nc\nd\n}\n89\n", 11);
    libasync::disconnect(h1);
    libasync::disconnect(h2);

    return 0;

}
