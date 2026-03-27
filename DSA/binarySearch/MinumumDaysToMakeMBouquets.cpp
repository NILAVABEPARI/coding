#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    bool possible(vector<int> nums, int days, int k, int m)
    {
        int noOfB = 0, cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= days)
                cnt++;
            else
            {
                noOfB += cnt / k;
                cnt = 0;
            }
        }
        noOfB += cnt / k;
        return noOfB >= m;
    }

public:
    int roseGarden(vector<int> nums, int k, int m)
    {
        // check for impossible case
        long long val = m * 1ll * k * 1ll;
        if (val > nums.size())
            return -1;

        int low = INT_MAX, high = INT_MIN, ans = -1;
        for (auto &it : nums)
        {
            low = min(low, it);
            high = max(high, it);
        }
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (possible(nums, mid, k, m))
            {
                high = mid - 1;
                ans = mid;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int m = 2, k = 3;
    Solution sol;
    cout << "number of days -- " << sol.roseGarden(arr, m, k);
    return 0;
}