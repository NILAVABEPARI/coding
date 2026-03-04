#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size(), l = 0, h = n - 1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[mid] == nums[l] && nums[mid] == nums[h])
            {
                l++;
                h--;
            }
            else if (nums[mid] >= nums[l])
            {
                if (nums[l] <= target && target <= nums[mid])
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            else
            {
                if (nums[mid] <= target && target <= nums[h])
                    l = mid + 1;
                else
                    h = mid - 1;
            }
        }
        return false;
    }
};