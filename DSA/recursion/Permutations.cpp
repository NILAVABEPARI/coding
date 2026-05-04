#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // brute force
    // TC -- O (n! * n)   SC -- O (n) + O (n) + O (n) auxilary recursion space
    // void recur(vector<vector<int>> &ans, vector<int> &ds, vector<int> &freq, vector<int> &nums)
    // {
    //     if (ds.size() == nums.size())
    //     {
    //         ans.push_back(ds);
    //         return;
    //     }
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         if (!freq[i])
    //         {
    //             ds.push_back(nums[i]);
    //             freq[i] = 1;
    //             recur(ans, ds, freq, nums);
    //             ds.pop_back();
    //             freq[i] = 0;
    //         }
    //     }
    // }
    // vector<vector<int>> permute(vector<int> &nums)
    // {
    //     vector<vector<int>> ans;
    //     vector<int> ds;
    //     vector<int> freq(nums.size(), 0);
    //     recur(ans, ds, freq, nums);
    //     return ans;
    // }

    void recur(int ind, vector<vector<int>> &ans, vector<int> &nums)
    {
        if (ind == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = ind; i < nums.size(); i++)
        {
            swap(nums[i], nums[ind]);
            recur(ind + 1, ans, nums);
            swap(nums[i], nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        recur(0, ans, nums);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans = sol.permute(arr);
    cout << "premutations -- " << endl;
    for (auto &it : ans)
    {
        cout << "[";
        for (auto &i : it)
            cout << i << ", ";
        cout << "]";
    }
    return 0;
}
