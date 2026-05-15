#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> bubbleSort(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--)
        {
            bool flag = false;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] > nums[j + 1])
                {
                    swap(nums[j], nums[j + 1]);
                    flag = true;
                }
            }
            if (!flag)
                break;
        }
        return nums;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {7, 4, 1, 5, 3};
    vector<int> ans = sol.bubbleSort(arr);
    for (auto &it : ans)
        cout << it << " ";
    return 0;
}