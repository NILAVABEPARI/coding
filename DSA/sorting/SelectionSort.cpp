/*
 * selection sort and bubble sort are opposites of each other
 * selection sorts from the start by finding the min element in current subarray
 * bubble sort sorts from the end by placing the max element in the end of the array
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> selectionSort(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int minInd = i;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] < nums[minInd])
                    minInd = j;
            }
            if (minInd != i)
                swap(nums[minInd], nums[i]);
        }
        return nums;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {7, 4, 1, 5, 3};
    vector<int> ans = sol.selectionSort(arr);
    for (auto &it : ans)
        cout << it << " ";
    return 0;
}