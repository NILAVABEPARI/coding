#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int upperBound(vector<int> &nums, int x)
    {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= x)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};

int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int x = 9;
    Solution sol;
    cout << "upper bound -- " << sol.upperBound(arr, x);
    return 0;
}