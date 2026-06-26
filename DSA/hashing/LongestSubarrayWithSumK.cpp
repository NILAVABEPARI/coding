#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int k)
    {
        unordered_map<long long, int> mp;
        long long sum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum == k)
                ans = max(ans, i + 1);
            if (mp.find(sum) == mp.end())
                mp[sum] = i;
            if (mp.find(sum - k) != mp.end())
                ans = max(ans, i - mp[sum - k]);
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {-5, 8, -14, 2, 4, 12};
    int k = -5;
    Solution sol;
    cout << "longest subarray -- " << sol.longestSubarray(nums, k);
    return 0;
}