/*
 * Tyler Filla
 * OPC18 - Problem 2
 */

#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    std::set<int> s1;
    std::set<int> s2;
    std::set<int> s_union;
    std::set<int> s_inter;

    int i = 1;
    int n1 = std::atoi(argv[i++]);

    for (int j = 0; j < n1; ++j)
    {
        s1.insert(std::atoi(argv[i++]));
    }

    int n2 = std::atoi(argv[i++]);

    for (int j = 0; j < n2; ++j)
    {
        s2.insert(std::atoi(argv[i++]));
    }

    // Union
    s_union.insert(s1.begin(), s1.end());
    s_union.insert(s2.begin(), s2.end());

    // Intersect
    std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(s_inter, s_inter.begin()));

    std::cout << s_union.size();

    for (std::set<int>::iterator i = s_union.begin(); i != s_union.end(); ++i)
    {
        std::cout << " " << *i;

/*
        if (std::distance(i, s_union.end()) != 1)
        {
            std::cout << " ";
        }*/
    }

    std::cout << " " << s_inter.size();

    for (std::set<int>::iterator i = s_inter.begin(); i != s_inter.end(); ++i)
    {
        std::cout << " " << *i;
    }

    return 0;
}
