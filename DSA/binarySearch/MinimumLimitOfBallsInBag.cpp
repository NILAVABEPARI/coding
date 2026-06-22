#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int low = 1, high = 0, ans = 0;
        for (auto &it : nums)
            high = max(high, it);
        while (low < high)
        {
            int mid = low + ((high - low) / 2), cnt = 0;
            for (auto &it : nums)
                cnt += (it - 1) / mid;
            if (cnt <= maxOperations)
            {
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
    vector<int> nums = {7, 17}; // {2, 4, 8, 2};
    int operations = 2;
    Solution sol;
    cout << "minimum penalty -- " << sol.minimumSize(nums, operations);
    return 0;
}