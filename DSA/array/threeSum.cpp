#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    // !! brute force -- using 3 loops
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        set<vector<int>> st;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

    // !! better -- using 2 loops
    vector<vector<int>> threeSum2(vector<int> &nums)
    {
        int n = nums.size();
        set<vector<int>> st;
        for (int i = 0; i < n - 1; i++)
        {
            set<int> hashSet;
            for (int j = i + 1; j < n; j++)
            {
                int third = -(nums[i] + nums[j]);
                if (hashSet.find(third) != hashSet.end())
                {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashSet.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

    // !! optimal -- using 2 pointers and sorting
    vector<vector<int>> threeSum3(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            // skip duplicates for i
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = n - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0)
                    right--;
                else if (sum < 0)
                    left++;
                else
                {
                    vector<int> temp = {nums[i], nums[left], nums[right]};
                    ans.push_back(temp);
                    // skip duplicates for left and right
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {2, -2, 0, 3, -3, 5};
    vector<vector<int>> ans = s.threeSum3(arr);
    cout << "Triplets -- " << endl;
    for (auto &it : ans)
    {
        cout << "[";
        for (auto &i : it)
            cout << i << ", ";
        cout << "] " << endl;
    }
    return 0;
}