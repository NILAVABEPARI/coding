#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfOddSubarrays(vector<int> &nums, int k)
    {
        int subArrayCount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int cnt = 0;
            for (int j = i; j < nums.size(); j++)
            {
                if (nums[j] % 2 == 1)
                    cnt++;
                if (cnt == k)
                    subArrayCount++;
                if (cnt > k)
                    break;
            }
        }
        return subArrayCount;
    }
};