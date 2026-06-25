#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // memoization --
    int fib(int n, vector<int> &dp)
    {
        if (n <= 1)
            return n;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    }
};

int main()
{
    Solution sol;
    int n = 15;
    // vector<int> dp(n + 1, -1);
    // cout << "ans -- " << sol.fib(n, dp);

    // tabulation --
    // vector<int> dp(n + 1, 0);
    // dp[0] = 0;
    // dp[1] = 1;
    // for (int i = 2; i <= n; i++)
    //     dp[i] = dp[i - 1] + dp[i - 2];
    // cout << "ans -- " << dp[n];

    // space optimization --
    int prevLast = 0, prev = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev + prevLast;
        prevLast = prev;
        prev = curr;
    }
    cout << "ans -- " << prev;
    return 0;
}