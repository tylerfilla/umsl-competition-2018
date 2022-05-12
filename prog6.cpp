/*
 * Tyler Filla
 * OPC18 - Problem 6
 */

#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <climits>

static double dist(double x1, double y1, double x2, double y2)
{
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

static double calc(int Ax, int Ay, int Bx, int By, int Cx, int Cy)
{
    return dist(Ax, Ay, Cx, Cy) + dist(Bx, By, Cx, Cy);
}

static int find(int Ax, int Ay, int Bx, int By)
{
    double min_dist = INT_MIN;
    for (int i = -500; i < 500; ++i)
    {
        if (calc(Ax, Ay, Bx, By, i, 0) < min_dist)
        {
            std::cout << i << "\n";
        }
    }

    return (int) min_dist;
}

int main(int argc, char* argv[])
{
    int n1 = std::atoi(argv[1]);
    int n2 = std::atoi(argv[2]);
    int n3 = std::atoi(argv[3]);
    int n4 = std::atoi(argv[4]);

    std::cout << find(n1, n2, n3, n4);

    return 0;
}
