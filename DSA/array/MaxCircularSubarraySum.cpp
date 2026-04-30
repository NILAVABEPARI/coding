#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // brute force -- using 2 loops
    int maxCircularSum(vector<int> &arr)
    {
        int n = arr.size(), maxSum = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int currSum = 0;
            for (int j = 0; j < n; j++)
            {
                int index = (i + j) % n;
                currSum += arr[index];
                maxSum = max(maxSum, currSum);
            }
        }
        return maxSum;
    }

    // using kadane's Algorithm --
    int maxCircularSum2(vector<int> &arr)
    {
        int totalSum = 0, maxSum = arr[0], minSum = arr[0], currMaxSum = 0, currMinSum = 0, n = arr.size();
        for (int i = 0; i < n; i++)
        {
            totalSum += arr[i];

            // kadane's algo to find the max subarray sum
            currMaxSum = max(currMaxSum + arr[i], arr[i]);
            maxSum = max(maxSum, currMaxSum);

            // kadane's algo to find the min subarray sum
            currMinSum = min(currMinSum + arr[i], arr[i]);
            minSum = min(currMinSum, minSum);
        }

        int normalSum = maxSum;
        int circularSum = totalSum - minSum;

        if (totalSum == minSum)
            return normalSum;

        return max(normalSum, circularSum);
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
    cout << " maxSum -- " << sol.maxCircularSum(arr);
    return 0;
}