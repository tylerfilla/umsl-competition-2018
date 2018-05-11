/*
 * Tyler Filla
 * OPC18 - Problem 1
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
    std::vector<std::string> queue;

    std::ifstream in(argv[1]);

    while (in.good())
    {
        std::string act;
        in >> act;

        if (act == "enqueue")
        {
            std::string tgt;
            in >> tgt;
            std::string name;
            in >> name;
            if (tgt == "front")
            {
//                std::cout << "push front " << name << "\n";
                queue.insert(queue.begin(), name);
            }
            else if (tgt == "end")
            {
//                std::cout << "push back " << name << "\n";
                queue.push_back(name);
            }
        }
        else if (act == "dequeue")
        {
//            std::cout << "pop\n";
            std::string front = queue.front();
            queue.erase(queue.begin());
        }
    }

    for (std::vector<std::string>::iterator i = queue.begin(); i != queue.end(); ++i)
    {
        std::cout << *i;

        if (i + 1 != queue.end())
        {
            std::cout << ",";
        }
    }

//    std::cout << "\n";

    return 0;
}
