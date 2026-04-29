#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countPairsWithinDistance(vector<int> &nums, int distance)
    {
        int left = 0, cnt = 0;
        for (int right = 1; right < nums.size(); right++)
        {
            while (nums[right] - nums[left] > distance)
                left++;
            cnt += right - left;
        }
        return cnt;
    }
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size(), minDist = 0, maxDist = nums.back() - nums.front();
        while (minDist < maxDist)
        {
            int midDist = (minDist + (maxDist - minDist)) / 2;
            if (countPairsWithinDistance(nums, midDist) < k)
                minDist = midDist + 1;
            else
                maxDist = midDist;
        }
        return minDist;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 6, 1};
    cout << "kth smallest distance -- " << sol.smallestDistancePair(arr, 3);
    return 0;
}