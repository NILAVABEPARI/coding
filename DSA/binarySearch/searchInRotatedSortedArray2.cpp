#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchInARotatedSortedArrayII(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // left side is sorted
            if (nums[mid] == target)
                return true;
            // !! extra check for duplicates -- if extremes are same as mid, reduce the window size
            else if (nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low++;
                high--;
            }
            else if (nums[low] <= nums[mid])
            {
                // check if target actually exists in the range
                if (nums[low] <= target && target <= nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            // right side is sorted
            else
            {
                // check if target actually exists in the range
                if (nums[mid] <= target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int target = 7;
    cout << s.searchInARotatedSortedArrayII(arr, target);
    return 0;
}