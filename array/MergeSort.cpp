#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    void merge(vector<int> &nums, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high)
        {
            if (nums[left] < nums[right])
                temp.push_back(nums[left++]);
            else
                temp.push_back(nums[right++]);
        }
        while (left <= mid)
            temp.push_back(nums[left++]);
        while (right <= high)
            temp.push_back(nums[right++]);
        for (int i = 0; i < temp.size(); i++)
            nums[low + i] = temp[i];
    }
    void mergeSortHelper(vector<int> &nums, int low, int high)
    {
        // if array has 1 or no elements then it is already sorted
        // thats why we are checking low < high
        if (low < high)
        {
            int mid = low + (high - low) / 2;
            mergeSortHelper(nums, low, mid);
            mergeSortHelper(nums, mid + 1, high);
            merge(nums, low, mid, high);
        }
    }

public:
    vector<int> mergeSort(vector<int> &nums)
    {
        mergeSortHelper(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main()
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