#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> insertionSort(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            int j = i;
            while (j >= 0 && nums[j - 1] > nums[j])
            {
                swap(nums[j - 1], nums[j]);
                j--;
            }
        }
        return nums;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {7, 4, 1, 5, 3};
    vector<int> ans = sol.insertionSort(arr);
    for (auto &it : ans)
        cout << it << " ";
    return 0;
}