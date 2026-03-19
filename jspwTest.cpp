#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<int> merge(vector<int> &nums, int low, int mid, int high)
    {
        vector<int> left;
        vector<int> right;
        for (int i = low; i < mid; i++)
            left[i] = nums[low + i];
        for (int i = mid; i < high; i++)
            right[i] = nums[mid + i];
        int i = 0, j = 0, k = low;
        while (i < left.size() && j < right.size())
        {
            if (left[i] < right[j])
                nums[k++] = left[i++];
            else
                nums[k++] = right[j++];
        }
        while (i < left.size())
            nums[low + i] = left[i++];
        while (j < right.size())
            nums[mid + j] = right[j++];
        return nums;
    }
    vector<int> mergeSortHelper(vector<int> &nums, int low, int high)
    {
        if (low <= high)
        {
            int mid = (high + low) / 2;
            mergeSortHelper(nums, low, mid);
            mergeSortHelper(nums, mid + 1, high);
            merge(nums, low, mid, high);
        }
    }

public:
    vector<int> mergeSort(vector<int> &nums)
    {
        return mergeSortHelper(nums, 0, nums.size() - 1);
    }
}

int
main()
{
    vector<int> arr = {9, 4, 7, 6, 3, 1, 5};
    int n = arr.size();

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Create an instance of the Solution class
    Solution sol;
    // Function call to sort the array
    vector<int> sortedArr = sol.mergeSort(arr);

    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++)
        cout << sortedArr[i] << " ";
    cout << endl;

    return 0;
}