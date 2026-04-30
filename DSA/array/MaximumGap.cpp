#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return 0;
        vector<int> maxBucketEle(n - 1, INT_MIN), minBucketEle(n - 1, INT_MAX);
        int maxEle = INT_MIN, minEle = INT_MAX, maxGap = 0;
        for (auto &it : nums)
        {
            maxEle = max(maxEle, it);
            minEle = min(minEle, it);
        }
        int bucketSize = (int)(ceil((double)(maxEle - minEle) / (n - 1)));
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == maxEle || nums[i] == minEle)
                continue;
            int bucketIndex = (nums[i] - minEle) / bucketSize;
            maxBucketEle[bucketIndex] = max(maxBucketEle[bucketIndex], nums[i]);
            minBucketEle[bucketIndex] = min(minBucketEle[bucketIndex], nums[i]);
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (minBucketEle[i] == INT_MAX)
                continue;
            maxGap = max(maxGap, minBucketEle[i] - minEle);
            minEle = maxBucketEle[i];
        }

        // !! if array has only 2 elements --
        maxGap = max(maxGap, maxEle - minEle);

        return maxGap;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {21, 9, 25, 3, 37, 43, 49, 29};
    cout << "maximum gap -- " << sol.maximumGap(arr);
    return 0;
}