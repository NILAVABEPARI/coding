#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // brute force -- generate all subarrays of all sizes -- O (n^3)
    // int maxSubarraySize(vector<int> &arr, int k)
    // {
    //     int n = arr.size(), ans = -1;
    //     for (int i = 1; i <= n; i++)
    //     {
    //         int maxSum = INT_MIN;
    //         for (int j = 0; j < n - i + 1; j++)
    //         {
    //             int sum = 0;
    //             for (int k = j; k < j + i; k++)
    //                 sum += arr[k];
    //             maxSum = max(maxSum, sum);
    //         }
    //         if (maxSum <= k)
    //             ans = max(ans, i);
    //     }
    //     return ans;
    // }

    // better using binary search on size of subarray
    // int maxSubarraySize(vector<int> &arr, int k)
    // {
    //     int n = arr.size(), low = 1, high = n;
    //     while (low < high)
    //     {
    //         int mid = low + (high - low) / 2;
    //         int sum = 0, maxSum = INT_MIN;
    //         for (int i = 0; i < n; i++)
    //         {
    //             sum += arr[i];
    //             if (i >= mid)
    //                 sum -= arr[i - mid];
    //             if (i >= mid - 1)
    //                 maxSum = max(maxSum, sum);
    //         }
    //         if (maxSum <= k)
    //             low = mid + 1;
    //         else
    //             high = mid - 1;
    //     }
    //     if (high == 0)
    //         return -1;
    //     return high;
    // }

    // optimal -- using sliding window
    int maxSubarraySize(vector<int> &arr, int k)
    {
        int n = arr.size(), start = 0, end = 0, sum = 0, minLen = n + 1;
        while (end < n)
        {
            sum += arr[end];
            end++;
            while (sum > k)
            {
                minLen = min(minLen, end - start);
                sum -= arr[start++];
            }
        }
        return minLen - 1 == 0 ? -1 : minLen - 1;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 3, 4};
    int k = 8;
    cout << "max subarray size -- " << sol.maxSubarraySize(arr, k) << endl;
    return 0;
}