#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size(), low = 0, high = n - 1, ans = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target)
            {
                if (nums[mid] == target)
                    return mid;
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 3, 5, 6};
    cout << sol.searchInsert(arr, 0);
    return 0;
}