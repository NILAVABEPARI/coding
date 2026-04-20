#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // !! very important and need revision
    int findMin(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + ((high - low) / 2);
            if (nums[mid] < nums[high])
                high = mid;
            else if (nums[mid] > nums[high])
                low = mid + 1;
            else
                high--;
        }
        return nums[low];
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 2, 2, 0, 1};
    cout << "minimum -- " << sol.findMin(nums);
    return 0;
}