#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // memoization --
    // int cs(int n, vector<int> dp)
    // {
    //     if (n <= 1)
    //         return 1;
    //     if (dp[n] != -1)
    //         return dp[n];
    //     return dp[n] = cs(n - 1, dp) + cs(n - 2, dp);
    // }
    // int climbStairs(int n)
    // {
    //     vector<int> dp(n + 1, -1);
    //     return cs(n, dp);
    // }

    // tabulation --
    // int climbStairs(int n)
    // {
    //     vector<int> dp(n + 1, 0);
    //     dp[0] = 1;
    //     dp[1] = 1;
    //     for (int i = 2; i <= n; i++)
    //         dp[i] = dp[i - 1] + dp[i - 2];
    //     return dp[n];
    // }

    // space optimization --
    int climbStairs(int n)
    {
        int prevLast = 1, last = 1;
        for (int i = 2; i <= n; i++)
        {
            int curr = last + prevLast;
            prevLast = last;
            last = curr;
        }
        return last;
    }
};

int main()
{
    Solution sol;
    int n = 15;
    cout << "ans -- " << sol.climbStairs(n);
}