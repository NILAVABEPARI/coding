#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubsequence(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int longest = 1, cnt = 1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] + 1 == nums[i + 1])
                cnt++;
            else if (nums[i] != nums[i + 1])
            {
                longest = max(cnt, longest);
                cnt = 1;
            }
        }
        return max(longest, cnt);
    }
}

int
main()
{
    return 0;
}