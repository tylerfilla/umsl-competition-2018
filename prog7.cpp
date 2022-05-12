/*
 * Tyler Filla
 * OPC18 - Problem 7
 */

#include <sstream>
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
/*
const int rows = 4;
const int cols = 5;

int matrix[rows][cols] = {
    { 5, -3, 27, 8, 11, },
    { 15, 0, -2, 6, -2, },
    { 1, 3, 18, 4, -8, },
    { 11, 18, 36, 17, 2, },
};
*/

int rows = -1;
int cols = -1;
std::vector<std::vector<int> > matrix;

static int get_cell(int row, int col)
{
    while (row <= 0)
    {
        row += rows;
    }

    while (col <= 0)
    {
        col += cols;
    }

    return matrix[(row - 1) % rows][(col - 1) % cols];
}

int main(int argc, char* argv[])
{
    std::ifstream in(argv[1]);

    std::string line;
    while (std::getline(in, line))
    {
        std::vector<int> v_new;
        matrix.push_back(v_new);

        std::vector<int>& row = matrix.back();

        std::stringstream ss;
        ss << line;

        int k = -1;
        while (ss >> k)
        {
            row.push_back(k);
        }
    }

    rows = matrix.size();
    cols = matrix.front().size();

    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col)
        {
            int n1 = get_cell(row, col);
            int n2 = get_cell(row, col + 1);
            int n3 = get_cell(row + 1, col);
            int n4 = get_cell(row + 1, col + 1);

            if (n1 + n2 + n3 + n4 == 0)
            {
                int acc = 0;
                for (int srow = row - 1; srow <= row + 2; ++srow)
                {
                    for (int scol = col - 1; scol <= col + 2; ++scol)
                    {
                        if (srow == row && scol == col)
                            continue;
                        if (srow == row && scol == col + 1)
                            continue;
                        if (srow == row + 1 && scol == col)
                            continue;
                        if (srow == row + 1 && scol == col + 1)
                            continue;

                        acc += get_cell(srow, scol);
                    }
                }
                std::cout << acc;
                return 0;
            }
        }
    }

    return 0;
}
