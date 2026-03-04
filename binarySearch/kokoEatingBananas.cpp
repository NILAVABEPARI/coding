class Solution
{
    int maxBananas(vector<int> nums)
    {
        int maxBananas = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            maxBananas = max(maxBananas, nums[i]);
        }
        return maxBananas;
    }
    int checkHours(vector<int> nums, int cap)
    {
        int h = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            h + = ceil((double)nums[i] / (double)cap);
        }
        return h;
    }

public:
    int bananas(vector<int> nums, int hours)
    {
        int n = nums.size(), l = 1, h = maxBananas(nums);
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (checkHours(nums, mid) > hours)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return l;
    }
};