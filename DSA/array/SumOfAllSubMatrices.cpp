#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // brute force --
    int matrixSum(vector<vector<int>> matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        int res = 0;
        for (int startRow = 0; startRow < n; startRow++)
        {
            for (int startCol = 0; startCol < m; startCol++)
            {
                for (int endRow = startRow; endRow < n; endRow++)
                {
                    for (int endCol = startCol; endCol < m; endCol++)
                    {
                        int submatrixSUm = 0;

                        for (int i = startRow; i <= endRow; i++)
                        {
                            for (int j = startCol; j <= endCol; j++)
                                submatrixSUm += matrix[i][j];
                        }
                        res += submatrixSUm;
                    }
                }
            }
        }
        return res;
    }

    // optimal -- check how many times an element contributes to the sum
    /*
     * For each element at position (i ,j), calculate how many different top-left corners could form a submatrix containing it: (i+1)*(j+1).
     * Calculate how many different bottom-right corners could form a submatrix containing it: (n-i)*(n-j).
     */
    int matrixSum2(vector<vector<int>> matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                res += (matrix[i][j] * (i + 1) * (j + 1) * (n - i) * (m - j));
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "matrix sum -- " << sol.matrixSum2(matrix);
    return 0;
}