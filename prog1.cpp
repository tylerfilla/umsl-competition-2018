/*
 * Tyler Filla
 * OPC18 - Problem 1
 */

#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>

static bool is_wrap(std::string s1, std::string s2)
{
    std::string original_s2 = s2;

    bool match = false;

    do
    {
        // Rotate the second string
        std::rotate(s2.begin(), s2.begin() + 1, s2.end());

        if (s1 == s2)
        {
            match = true;
        }
    } while (s2 != original_s2);

    return match;
}

static bool chk_wrapping(std::string str, int n)
{
    long j = std::atol(str.c_str());

//    std::cout << "checking " << j << "\n";

    bool good = true;

    for (int i = 2; i <= n; ++i)
    {
        std::stringstream ss;
        ss << (j * i);
        std::string m;
        ss >> m;

//        std::cout << "multiplied by " << i << ": " << m << "\n";

        good = good && is_wrap(str, m);
    }

    return good;
}

int main(int argc, char* argv[])
{
    std::string s(argv[1]);
    int k = s.length();

    if (chk_wrapping(s, k))
    {
        std::cout << "wrap";
    }
    else
    {
        std::cout << "not wrap";
    }

    return 0;
}
