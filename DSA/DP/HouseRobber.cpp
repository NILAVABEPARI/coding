#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int recur(vector<int> &nums, int ind, vector<int> &dp)
    {
        if (ind == 0)
            return nums[0];
        if (ind < 0)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];

        // take
        int take = nums[ind] + recur(nums, ind - 2, dp);
        // not take
        int nTake = recur(nums, ind - 1, dp);
        return dp[ind] = max(take, nTake);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return recur(nums, n - 1, dp);
    }

    // tabulation --
    int rob2(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            // take --
            int take = nums[i];
            if (i > 1)
                take += dp[i - 2];

            // not take --
            int nTake = dp[i - 1];
            dp[i] = max(take, nTake);
        }
        return dp[n - 1];
    }

    // space optimization --
    int rob3(vector<int> &nums)
    {
        int n = nums.size();
        int prev1 = nums[0], prev2 = 0;
        for (int i = 1; i <= n; i++)
        {
            // take --
            int take = nums[i];
            if (i > 1)
                take += prev2;

            // not take --
            int nTake = prev1;
            int curr = max(take, nTake);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << "ans -- " << sol.rob(nums);
}