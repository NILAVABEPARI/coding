#include <bits.stdc++.h>
#using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        // brute force
        // int n = nums.size(), l = 0, r = 0, zeros = 0, maxi = 0;
        // while (r < n)
        // {
        //     if (nums[r] == 0)
        //         zeros++;
        //     while (zeros > k)
        //     {
        //         if (nums[l] == 0)
        //             zeros--;
        //         l++;
        //     }
        //     maxi = max(maxi, r - l + 1);
        //     r++;
        // }
        // return maxi;

        // optimal
        int n = nums.size(), l = 0, r = 0, zeros = 0, maxi = 0;
        while (r < n)
        {
            if (nums[r] == 0)
                zeros++;
            if (zeros > k)
            {
                if (nums[l] == 0)
                    zeros--;
                l++;
            }
            if (zeros <= k)
                maxi = max(maxi, r - l + 1);
            r++;
        }
        return maxi;
    }
};