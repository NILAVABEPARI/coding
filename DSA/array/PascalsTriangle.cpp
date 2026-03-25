#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> pascalTriangleIII(int n)
    {
        vector<vector<int>> ans;
        if (n == 0)
            return ans;
        ans.push_back({{1}});
        for (int i = 1; i < n; i++)
        {
            vector<int> temp(i + 1);
            temp[0] = 1;
            temp[temp.size() - 1] = 1;
            for (int j = 1; j < i; j++)
                temp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            ans.push_back(temp);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> ans = sol.pascalTriangleIII(5);
    for (auto &row : ans)
    {
        for (auto &col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}