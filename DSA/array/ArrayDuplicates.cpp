#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0)
                ans.push_back(abs(nums[i]));
            else
                nums[index] *= -1;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {2, 3, 1, 2, 3, 4, 4};
    vector<int> ans = sol.findDuplicates(arr);
    cout << "duplicates -- ";
    for (auto it : ans)
        cout << it << " ";
    return 0;
}