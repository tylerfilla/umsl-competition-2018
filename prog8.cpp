/*
 * Tyler Filla
 * OPC18 - Problem 8
 */

#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <climits>
#include <vector>

static char chfor(int num)
{
    switch (num)
    {
    case 0:
        return '0';
    case 1:
        return '1';
    case 2:
        return '2';
    case 3:
        return '3';
    case 4:
        return '4';
    case 5:
        return '5';
    case 6:
        return '6';
    case 7:
        return '7';
    case 8:
        return '8';
    case 9:
        return '9';
    default:
        return '?';
    }
}

static void sub(std::string& str, int A, int B, int C)
{
//    std::cout << "subbing " << str << " with A=" << A << ", B=" << B << ", C=" << C << "\n";
    for (int i = 0; i < str.length(); ++i)
    {
        switch (str[i])
        {
        case 'A':
            str[i] = chfor(A);
            break;
        case 'B':
            str[i] = chfor(B);
            break;
        case 'C':
            str[i] = chfor(C);
            break;
        }
    }
}

static bool test(std::string s1, std::string s2, std::string s3, int A, int B, int C)
{
//    std::cout << s1 << "\n";
    sub(s1, A, B, C);
//    std::cout << s1 << "\n";
    sub(s2, A, B, C);
    sub(s3, A, B, C);

    int n1 = std::atoi(s1.c_str());
    int n2 = std::atoi(s2.c_str());
    int n3 = std::atoi(s3.c_str());

    return (n1 + n2) == n3;
}

static int run(std::string& s1, std::string& s2, std::string& s3, int M)
{
    for (int A = 0; A < M; ++A)
    {
        for (int B = 0; B < M; ++B)
        {
            for (int C = 0; C < M; ++C)
            {
                if (test(s1, s2, s3, A, B, C))
                {
                    std::cout << A << " " << B << " " << C;// << "\n";
                    return 0;
                }
            }
        }
    }

    return 1;
}

int main(int argc, char* argv[])
{
    std::string s1(argv[1]);
    std::string s2(argv[2]);
    std::string s3(argv[3]);

    for (int M = 0; M < INT_MAX; ++M)
    {
        if (run(s1, s2, s3, M) == 0)
            break;
    }

    return 0;
}
