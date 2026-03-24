#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // !! better approach
        // // element, index
        // unordered_map<int, int> mp;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (mp.find(target - nums[i]) != mp.end())
        //         return {mp[nums[i]], i};
        //     mp[nums[i]] = i;
        // }
        // return {-1, -1};

        // !! optimal approach
        int n = nums.size();
        vector<vector<int>> eleIndex;
        vector<int> ans;
        for (int i = 0; i < n; i++)
            eleIndex.push_back({nums[i], i});

        sort(eleIndex.begin(), eleIndex.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        int left = 0, right = n - 1;
        while (left < right)
        {
            int sum = eleIndex[left][0] + eleIndex[right][0];
            if (sum == target)
            {
                if (eleIndex[left][1] < eleIndex[right][1])
                {
                    ans.push_back(eleIndex[left][1]);
                    ans.push_back(eleIndex[right][1]);
                }
                else
                {
                    ans.push_back(eleIndex[right][1]);
                    ans.push_back(eleIndex[left][1]);
                }
                return ans;
            }
            else if (sum < target)
                left++;
            else
                right--;
        }
        return {-1, -1};
    }
};

int main()
{
    vector<int> arr = {-6, 7, 1, -7, 6, 2};
    int target = 3;
    Solution sol;
    vector<int> ans = sol.twoSum(arr, target);
    cout << "target indices -- " << ans[0] << ", " << ans[1];
    return 0;
}