#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && nums[j - 1] == nums[j])
                    continue;
                int left = j + 1, right = n - 1;
                while (left < right)
                {
                    long long sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum > target)
                        right--;
                    else if (sum < target)
                        left++;
                    else
                    {
                        vector<int> temp = {nums[i], nums[j], nums[left], nums[right]};
                        ans.push_back(temp);
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1])
                            left++;
                        while (left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {1, -2, 3, 5, 7, 9};
    int target = 7;
    Solution sol;
    vector<vector<int>> ans = sol.fourSum(arr, target);
    for (auto &row : ans)
    {
        cout << "[";
        for (auto &col : row)
            cout << col << ", ";
        cout << "], " << endl;
    }
    return 0;
}