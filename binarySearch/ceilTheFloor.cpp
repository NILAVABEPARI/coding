#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<int, int> getFloorAndCeil(vector<int> &nums, int target)
    {
        int n = nums.size(), l = 0, h = n - 1, floor = INT_MIN, ceil = INT_MAX;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (nums[mid] == target)
                return {nums[mid], nums[mid]};
            else if (nums[mid] > target)
            {
                ceil = nums[mid];
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
                floor = nums[mid];
            }
        }
        return {
            floor == INT_MIN ? -1 : floor, ceil == INT_MAX ? -1 : ceil};
    }
};

int main()
{
    return 0;
}