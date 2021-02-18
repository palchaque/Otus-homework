#include "custom_allocator.cpp"
#include "custom_list.cpp"

#include <iostream>
#include <string>
#include <map>
#include <memory>

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

    list.print_values();

    return 0;

}



