#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // brute force
    int subarraySum(vector<int> &nums, int k)
    {
        int i = 0, j = 0, n = nums.size(), cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += nums[j];
                if (sum == k)
                    cnt++;
            }
        }
        return cnt;
    }

    // optimal
    int subarraySum2(vector<int> &nums, int k)
    {
        int n = nums.size(), cnt = 0, prefixSum = 0;
        // sum, index
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            prefixSum += nums[i];
            int remaining = prefixSum - k;
            cnt += mp[remaining];
            mp[prefixSum] += 1;
        }
        return cnt;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {3, 1, 2, 4};
    cout << "number of subarrays -- " << sol.subarraySum2(arr, 6);
    return 0;
}