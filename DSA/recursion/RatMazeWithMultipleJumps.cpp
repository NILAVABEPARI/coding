#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool recur(int row, int col, int n, vector<vector<int>> &matrix, vector<vector<int>> &ans)
    {
        if (row >= n || col >= n)
            return false;

        // the last cell can be 0
        if (matrix[row][col] == 0 && !(row == n - 1 && col == n - 1))
            return false;

        // mark current cell as 1
        ans[row][col] = 1;

        if (row == n - 1 && col == n - 1)
            return true;

        for (int i = 1; i <= matrix[row][col]; i++)
        {
            // forward
            if (col + i < n && recur(row, col + i, n, matrix, ans))
                return true;

            // down
            if (row + i < n && recur(row + i, col, n, matrix, ans))
                return true;
        }
        ans[row][col] = 0;
        return false;
    }
    vector<vector<int>> ShortestDistance(vector<vector<int>> &matrix)
    {
        // Code here
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));
        if (n > 1 && matrix[0][0] == 0)
            return {{-1}};
        if (recur(0, 0, n, matrix, ans))
            return ans;
        return {{-1}};
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{2, 1, 0, 0},
                                  {3, 0, 0, 1},
                                  {0, 1, 0, 1},
                                  {0, 0, 0, 1}};
    vector<vector<int>> ans = sol.ShortestDistance(matrix);
    for (auto &it : ans)
    {
        for (auto &i : it)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}