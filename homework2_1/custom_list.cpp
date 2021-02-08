#include <iostream>

template<typename T, typename A, std::size_t size>
class custom_list
{
    std::size_t n = 0;
    A allocator;
    T values[size];
    public:
    custom_list() = default;
    ~custom_list() = default;

    void push_back(T value)
    {
        T* new_alloc = allocator.allocate(n);
        allocator.construct(new_alloc, value);
        values[n] = *new_alloc;
        n++;
    }

    T get(int index)
    {
        return values[index];
    }

    void print_values()
    {
      for (int i = 0; i<size; i++) {
          std::cout<<get(i)<<std::endl;
        }
    }

};
