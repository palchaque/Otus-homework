#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

void print_filtered(std::vector<std::vector<std::string>> &ip_pool, const std::string filter1)
{

    std::vector<std::vector<std::string>>::const_iterator it = std::find_if(ip_pool.begin(), ip_pool.end(), [filter1](std::vector<std::string> element){ return element[0] == filter1;});

    for(it->begin(); it != ip_pool.end(); ++it)
    {
        for(std::vector<std::string>::const_iterator ip_part = it->cbegin(); ip_part != it->cend(); ++ip_part)
        {
            if (ip_part != it->cbegin())
            {
                std::cout << ".";

            }
            std::cout << *ip_part;
        }
        std::cout << std::endl;
    }
}

void print_filtered(std::vector<std::vector<std::string>> &ip_pool, const std::string filter1, const std::string filter2)
{

    std::vector<std::vector<std::string>> filteredList;

    for(std::vector<std::vector<std::string> >::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
    {

            if(ip->at(0) == filter1 && ip->at(1) == filter2)
            {
                filteredList.push_back(*ip);

            }
    }

    for(std::vector<std::vector<std::string> >::const_iterator ip = filteredList.cbegin(); ip != filteredList.cend(); ++ip)
    {

        for(std::vector<std::string>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
        {
            if (ip_part != ip->cbegin())
            {
                std::cout << ".";

            }
            std::cout << *ip_part;
        }
        std::cout << std::endl;
    }
}

void print_filtered_any(std::vector<std::vector<std::string>> &ip_pool, const std::string value)
{
    std::vector<std::vector<std::string>> filteredList;

    for(std::vector<std::vector<std::string> >::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
    {
        bool haveValue = false;
        for(std::vector<std::string>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
        {
            if(!haveValue && *ip_part == value)
            {
                filteredList.push_back(*ip);
                haveValue = true;
            }
        }
    }

    for(std::vector<std::vector<std::string> >::const_iterator ip = filteredList.cbegin(); ip != filteredList.cend(); ++ip)
    {
        for(std::vector<std::string>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
        {

                if (ip_part != ip->cbegin())
                {
                    std::cout << ".";
                }
                std::cout << *ip_part;

        }
        std::cout << std::endl;
    }

}

int main(int argc, char const *argv[])
{

        struct {
                bool operator()(std::vector<std::string> a, std::vector<std::string> b) const
                {
                    for (int i=0; i<=3; i++)
                    {
                        if (a[i] != b[i]) return a[i] > b[i];
                        else continue;
                    }

                    return false;
                }
            } ipv4_sort;

        try
        {

        std::vector<std::vector<std::string> > ip_pool;

        for(std::string line; std::getline(std::cin, line);)
        {
            std::vector<std::string> v = split(line, '\t');
            ip_pool.push_back(split(v.at(0), '.'));
        }

        std::sort(ip_pool.begin(), ip_pool.end(), ipv4_sort);

        for(std::vector<std::vector<std::string> >::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
        {
            for(std::vector<std::string>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
            {
                if (ip_part != ip->cbegin())
                {
                    std::cout << ".";

                }
                std::cout << *ip_part;
            }
            std::cout << std::endl;
        }

        print_filtered(ip_pool, "1");

        print_filtered(ip_pool, "46", "70");

        print_filtered_any(ip_pool, "46");

    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
