/*
 * Tyler Filla
 * OPC18 - Problem 3
 */

#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>

static bool check(int n1, int n2, int n3)
{
    std::stringstream ss1;
    ss1 << n1;
    std::string s1 = ss1.str();

    bool neg1 = n1 < 0;

    if (neg1)
    {
        s1 = s1.substr(1);
    }

//    std::cout << s1 << "\n";

    std::stringstream ss2;
    ss2 << n2;
    std::string s2 = ss2.str();

    bool neg2 = n2 < 0;

    if (neg2)
    {
        s2 = s2.substr(1);
    }

//    std::cout << s2 << "\n";

    std::stringstream ss3;
    ss3 << n3;
    std::string s3 = ss3.str();

    bool neg3 = n3 < 0;

    if (neg3)
    {
        s3 = s3.substr(1);
    }

//    std::cout << s3 << "\n";

    bool neg_concat = neg1 != neg2;

//    std::cout << (s1 + s2) << "\n";
//    std::cout << (s2 + s1) << "\n";

    if (s1 + s2 == s3 && neg_concat == neg3)
    {
        return true;
    }
    else if (s2 + s1 == s3 && neg_concat == neg3)
    {
        return true;
    }

    return false;
}

static std::set<int> read_file(std::ifstream& in)
{
    std::set<int> v;

    int k;
    while (in >> k)
    {
        v.insert(k);
    }

    return v;
}

int main(int argc, char* argv[])
{
    std::ifstream in1(argv[1]);

    if (!in1)
    {
        std::cout << "ERROR";
        return 1;
    }

    std::ifstream in2(argv[2]);

    if (!in2)
    {
        std::cout << "ERROR";
        return 1;
    }

    int look_for = std::atoi(argv[3]);

    std::set<int> s1 = read_file(in1);
    std::set<int> s2 = read_file(in2);

    std::vector<int> v1(s1.begin(), s1.end());
    std::vector<int> v2(s2.begin(), s2.end());

    int num_combos = 0;

    for (int i = 0; i < v1.size(); ++i)
    {
        for (int j = 0; j < v2.size(); ++j)
        {
            if (check(v1[i], v2[j], look_for))
            {
//                std::cout << v1[i] << ", " << v2[j] << "\n";
                num_combos++;
            }
        }
    }

    std::cout << "MATCH " << num_combos;

    return 0;
}
