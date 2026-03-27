#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    long countHours(vector<int> nums, int hours)
    {
        long sum = 0;
        for (auto &it : nums)
            sum += ceil((double)it / hours);
        return sum;
    }

public:
    int minimumRateToEatBananas(vector<int> nums, int hours)
    {
        int low = 1, high = 0;
        for (auto &it : nums)
            high = max(high, it);
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (countHours(nums, mid) <= hours)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {3, 7, 6, 11};
    int hour = 8;
    cout << "minimum number of bananas -- " << sol.minimumRateToEatBananas(arr, hour);
    return 0;
}