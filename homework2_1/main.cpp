#include <iostream>
#include <string>
#include <map>
#include <memory>

template<typename T, size_t max_size>
class custom_allocator
{


private:
    size_t max_allocator_size = 0;
    size_t count = 0;
    uint8_t data[sizeof(T) * max_size];

public:
    custom_allocator() = default;
    ~custom_allocator() = default;

        using value_type = T;

        using pointer = T*;
        using const_pointer = const T*;
        using reference = T&;
        using const_reference = const T&;

    template<typename U>
       struct rebind {
           using other = custom_allocator<U, max_size>;
       };

       template<typename U>
           custom_allocator(const custom_allocator<U, max_size>&) {

           }

        T *allocate(std::size_t n)
        {

           if(max_allocator_size == 0)
           {
               max_allocator_size = max_size;
           }


            if(count > max_allocator_size)
            {
                   throw std::bad_alloc();
            }

            return reinterpret_cast<T *>(&data[sizeof(T) * count++]);

       }

       void deallocate(T *pointer, std::size_t n)
       {

           count-=n;
       }

       template<typename U, typename ...Args>
       void construct(U *p, Args &&...args) {
               new(p) U(std::forward<Args>(args)...);
           }

       void destroy(T *p) {
               p->~T();
           }

};

template<typename T, typename A, std::size_t size>
class custom_list
{
  private:
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

};


int getFactorial(const int &number)
{
    int factorial = 1;
    for(int i = 1; i <=number; ++i)
        {
            factorial *= i;
        }
    return factorial;
}

int main()
{

    auto myMap = std::map<int, int, std::less<int>, custom_allocator<std::pair<int, int>, 10>>{};

    for (int i = 0; i<= 9; i++)
    {
      myMap.emplace(i, getFactorial(i));
    }

    for (auto mapIterator : myMap)
    {
        std::cout<<mapIterator.first<<" "<<mapIterator.second<<std::endl;
    }


    custom_list<int, custom_allocator<int, 10>, 10> list{};

    for (int i = 0; i<= 9; i++)
    {
        list.push_back(i);
    }

    for (int i = 0; i<= 9; i++)
    {
        std::cout<<list.get(i)<<std::endl;
    }

    return 0;

}
