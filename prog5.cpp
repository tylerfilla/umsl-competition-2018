/*
 * Tyler Filla
 * OPC18 - Problem 5
 */

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iterator>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    if (argc == 0)
    {
        std::cout << "ERROR";
        return 1;
    }

    std::ifstream in(argv[1]);

    if (!in)
    {
        std::cout << "ERROR";
        return 1;
    }

    bool empty = true;

    int mx = 0;
    int my = 0;

    int mx_n = 0;
    int my_n = 0;

    int mx_e = 0;
    int my_e = 0;

    int mx_s = 0;
    int my_s = 0;

    int mx_w = 0;
    int my_w = 0;

    while (in.good())
    {
        std::string str;
        in >> str;

        for (int i = 0; i < str.length(); ++i)
        {
            empty = false;
            switch (str[i])
            {
            case 'N':
                my++;
                break;
            case 'E':
                mx++;
                break;
            case 'S':
                my--;
                break;
            case 'W':
                mx--;
                break;
            }

            if (mx > mx_e)
            {
                mx_e = mx;
                my_e = my;
            }

            if (mx < mx_w)
            {
                mx_w = mx;
                my_w = my;
            }

            if (my > my_n)
            {
                mx_n = mx;
                my_n = my;
            }

            if (my < my_s)
            {
                mx_s = mx;
                my_s = my;
            }
        }
    }

    if (empty)
    {
        std::cout << "ERROR";
        return 1;
    }

    std::cout << "(" << mx << "," << my << ")";
    std::cout << "(" << mx_n << "," << my_n << ")";
    std::cout << "(" << mx_e << "," << my_e << ")";
    std::cout << "(" << mx_s << "," << my_s << ")";
    std::cout << "(" << mx_w << "," << my_w << ")";
    //std::cout << "\n";

    return 0;
}
