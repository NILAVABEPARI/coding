#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int partition(vector<int> &nums, int low, int high)
    {
        int i = low, j = high, pivot = nums[low];
        while (i < j)
        {
            while (i <= high && nums[i] <= pivot)
                i++;
            while (j >= low && nums[j] > pivot)
                j--;
            if (i < j)
                swap(nums[i], nums[j]);
        }
        swap(nums[j], nums[low]);
        return j;
    }
    void quicksortHelper(vector<int> &nums, int low, int high)
    {
        if (low >= high)
            return;
        int pInd = partition(nums, low, high);
        quicksortHelper(nums, low, pInd - 1);
        quicksortHelper(nums, pInd + 1, high);
    }
    vector<int> quickSort(vector<int> &nums)
    {
        quicksortHelper(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {7, 4, 1, 5, 3};
    vector<int> ans = sol.quickSort(arr);
    for (auto &it : ans)
        cout << it << " ";
    return 0;
}