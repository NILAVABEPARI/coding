#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> countDistinct(vector<int> &arr, int k)
    {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
            if (i >= k - 1)
            {
                ans.push_back(mp.size());
                mp[arr[i - k]]--;
                if (mp[arr[i - k]] == 0)
                    mp.erase(arr[i - k]);
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;
    Solution sol;
    vector<int> ans = sol.countDistinct(nums, k);
    cout << "minimum jumps -- ";
    for (auto &it : ans)
        cout << it << " ";
    return 0;
}