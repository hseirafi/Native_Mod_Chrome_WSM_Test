#include <nan.h>
#include <utility>
#include <cassert>
#include <vector>
#include<iostream>
#include<array> 



//Eulerian Tour 
class Itinerary
{
    std::vector<string> str;
public:
    std::vector<string> findItinerary(std::vector<std::vector<string>> &tickets, std::string from)
    {
        size_t maxRange = 0;
        for (const auto &ticket : tickets)
        {
            maxRange = max(maxRange, to_size_t(*ticket.begin()));
            maxRange = max(maxRange, to_size_t(*&ticket.back()));
        }
        std::vector<multiset<size_t>> edges(maxRange + 1);
        for (const auto &ticket : tickets)
        {
            edges[to_size_t(*ticket.begin())].insert(to_size_t(*&ticket.back()));
        }
        visit(to_size_t(from), edges);
        return std::vector<string>(str.rbegin(), str.rend());
    }
    void visit(size_t curr, std::vector<multiset<size_t>> &edges)
    {
        while (edges[curr].size())
        {
            size_t next = *edges[curr].begin();
            edges[curr].erase(edges[curr].begin());
            visit(next, edges);
        }
        str.push_back(to_string(curr));
    }
 
    size_t to_size_t(string str)
    {
        size_t result = 0;
        for (size_t i = 0; i < 3; ++i)
        {
            result = result * 26 + str[i] - 'A';
        }
        return result;
    }

    string to_string(size_t res)
    {
        string str = "";
        str.resize(3);
        for (size_t i = 2; i >= 0; --i)
        {
            char c = res % 26 + 'A';
            res /= 26;
            str[i] = c;
        }
        return str;
    }
};