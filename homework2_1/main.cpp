#include "custom_allocator.cpp"
#include "custom_list.cpp"

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <benchmark/benchmark.h>


int getFactorial(const int &number)
{
    int factorial = 1;
    for(int i = 1; i <=number; ++i)
        {
            factorial *= i;
        }
    return factorial;
}

//#define RUN_BENCHMARK

#ifndef RUN_BENCHMARK

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
#endif


#ifdef RUN_BENCHMARK

static void insert_into_map(benchmark::State& state) {
    for (auto _ : state)
    {
        auto myMap = std::map<int, int>{};

        for (int i = 0; i<= 9; i++)
        {
          myMap.emplace(i, getFactorial(i));
        }

        for (auto mapIterator : myMap)
        {
            //std::cout<<mapIterator.first<<" "<<mapIterator.second<<std::endl;
        }
    }

}

static void insert_into_map_with_allocator(benchmark::State& state) {
    for (auto _ : state)
    {

        auto myMap = std::map<int, int, std::less<int>, custom_allocator<std::pair<int, int>, 10>>{};

        for (int i = 0; i<= 9; i++)
        {
          myMap.emplace(i, getFactorial(i));
        }

        for (auto mapIterator : myMap)
        {
            //std::cout<<mapIterator.first<<" "<<mapIterator.second<<std::endl;
        }
    }

}

static void insert_into_custom_container_with_default_allocator(benchmark::State& state) {
    for (auto _ : state)
    {
        custom_list<int, std::allocator<int>, 10> list;

        for (int i = 0; i<= 9; i++)
        {
            list.push_back(i);
        }
    }

}

static void insert_into_custom_container_with_custom_allocator(benchmark::State& state) {
    for (auto _ : state)
    {
        custom_list<int, custom_allocator<int, 10>, 10> list;

        for (int i = 0; i<= 9; i++)
        {
            list.push_back(i);
        }
    }

}

BENCHMARK(insert_into_map);

BENCHMARK(insert_into_map_with_allocator);

BENCHMARK(insert_into_custom_container_with_default_allocator);

BENCHMARK(insert_into_custom_container_with_custom_allocator);

BENCHMARK_MAIN();

#endif
