#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int recur(int W, vector<int> &val, vector<int> &wt, int ind, vector<vector<int>> &dp())
    {
        if (ind == 0)
        {
            if (wt[ind] <= W)
                return val[0];
            else
                return 0;
        }
        if (dp[ind][W] != -1)
            return dp[ind][W];
        int pick = INT_MIN;
        if (W >= wt[ind])
            pick = val[ind] + recur(W - wt[ind], val, wt, ind - 1, dp);
        int notPick = recur(W, val, wt, ind - 1, dp);
        return dp[ind][W] = max(pick, notPick);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        return recur(W, val, wt, n - 1, dp);
    }
};

int main()
{
    Solution sol;
    vector<int> val = {10, 40, 30, 50}, wt = {5, 4, 2, 3};
    cout << "ans -- " << sol.knapsack(5, val, wt);
}