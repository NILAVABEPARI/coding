#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int partition(vector<int> &nums, int low, int high)
    {
        int pivot = nums[low];
        int i = low, j = high;
        while (i < j)
        {
            while (nums[i] <= pivot && i <= high - 1)
                i++;
            while (nums[j] >= pivot && j >= low + 1)
                j--;
            if (i < j)
                swap(nums[i], nums[j]);
        }
        swap(nums[low], nums[j]);
        return j;
    }
    void quickSortHelper(vector<int> &nums, int low, int high)
    {
        // if the array has only 1 or no element then it is already sorted
        // thats why we are checking low < high
        if (low < high)
        {
            int partitionInd = partition(nums, low, high);
            quickSortHelper(nums, low, partitionInd - 1);
            quickSortHelper(nums, partitionInd + 1, high);
        }
    }

public:
    vector<int> quickSort(vector<int> &nums)
    {
        quickSortHelper(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main()
{
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Create an instance of Solution class
    Solution solution;

    // Function call to sort the array using quick sort
    vector<int> sortedArr = solution.quickSort(arr);

    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << sortedArr[i] << " ";
    }
    cout << endl;

    return 0;
}