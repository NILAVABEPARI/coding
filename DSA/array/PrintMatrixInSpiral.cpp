#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int left = 0, top = 0, right = matrix[0].size() - 1, bottom = matrix.size() - 1;
        vector<int> ans;
        while (left <= right && top <= bottom)
        {
            for (int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
            top++;
            for (int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                    ans.push_back(matrix[bottom][i]);
                bottom--;
            }
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12},
                                  {13, 14, 15, 16}};
    Solution sol;
    vector<int> ans = sol.spiralOrder(matrix);
    cout << "Elements in spiral order are: ";
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}