#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size(), maxSum = INT_MIN, currentSum = 0;
        for (int i = 0; i < n; i++)
        {
            currentSum += nums[i];
            maxSum = max(maxSum, currentSum);
            if (currentSum <= 0)
                currentSum = 0;
        }
        return maxSum;
    }
};
int main()
{
    vector<int> ans = /*{2, 3, 5, -2, 7, -4};*/ {-2, -3, -7, -2, -10, -4}; /* , {-1, 2, 3, -1, 2, -6, 5} */
    Solution sol;
    cout << "ans -- " << sol.maxSubArray(ans);
    return 0;
}