#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // !! very important and need revision
    // int findMin(vector<int> &nums)
    // {
    //     int low = 0, high = nums.size() - 1;
    //     while (low <= high)
    //     {
    //         int mid = low + ((high - low) / 2);
    //         if (nums[mid] < nums[high])
    //             high = mid;
    //         else if (nums[mid] > nums[high])
    //             low = mid + 1;
    //         else
    //             high--;
    //     }
    //     return nums[low];
    // }

    // !! easier to understand code --
    int findMin(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1, minEle = INT_MAX;
        while (low <= high)
        {
            // remove the duplicates from both ends
            while (low < high && nums[low] == nums[low + 1])
                low++;
            while (high > low && nums[high] == nums[high - 1])
                high--;
            int mid = low + (high - low) / 2;
            if (nums[mid] < minEle)
                minEle = nums[mid];
            if (nums[mid] > nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return minEle;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 2, 2, 0, 1};
    cout << "minimum -- " << sol.findMin(nums);
    return 0;
}