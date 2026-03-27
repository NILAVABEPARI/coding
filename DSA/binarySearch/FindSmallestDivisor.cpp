#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
private:
    long divisorCount(vector<int> &nums, int divisor)
    {
        long sum = 0;
        for (auto &it : nums)
            sum += (ceil)((double)it / divisor);
        return sum;
    }

public:
    int smallestDivisor(vector<int> &nums, int limit)
    {
        int low = 1, high = INT_MIN;
        for (auto it : nums)
            high = max(it, high);
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (divisorCount(nums, mid) <= limit)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};

int main()
{
    vector<int> arr = {8, 4, 2, 3};
    int limit = 10;
    Solution sol;
    cout << "Smallest divisor -- " << sol.smallestDivisor(arr, limit);
    return 0;
}