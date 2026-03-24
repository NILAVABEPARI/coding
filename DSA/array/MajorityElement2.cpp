#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> majorityElementTwo(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return {};
        int ele1 = INT_MIN, ele2 = INT_MIN, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == ele1)
                cnt1++;
            else if (nums[i] == ele2)
                cnt2++;
            else if (cnt1 == 0)
            {
                cnt1 = 1;
                ele1 = nums[i];
            }
            else if (cnt2 == 0)
            {
                cnt2 = 1;
                ele2 = nums[i];
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == ele1)
                cnt1++;
            if (nums[i] == ele2)
                cnt2++;
        }
        vector<int> ans;
        if (cnt1 > n / 3)
            ans.push_back(ele1);
        if (cnt2 > n / 3)
            ans.push_back(ele2);
        return ans;
    }
};

int main()
{
    vector<int> arr = {1, 2, 1, 1, 3, 2, 2, 3};
    Solution sol;
    vector<int> ans = sol.majorityElementTwo(arr);
    cout << "majority Element -- ";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}