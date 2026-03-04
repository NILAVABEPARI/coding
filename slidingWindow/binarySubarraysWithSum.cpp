#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int cntSubArraySum(vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0;
        int r = 0, l = 0, sum = 0, cnt = 0;
        while (r < nums.size())
        {
            sum += nums[r];
            while (sum > goal)
            {
                sum -= nums[l++];
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }

public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        // brute force --
        // int cnt = 0;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     int sum = 0;
        //     for (int j = i; j < nums.size(); j++)
        //     {
        //         sum += nums[j];
        //         if (sum == goal)
        //             cnt++;
        //         else if (sum > goal)
        //             break;
        //     }
        // }
        // return cnt;

        // optimal --
        return cntSubArraySum(nums, goal) - cntSubArraySum(nums, goal - 1);
    }
};