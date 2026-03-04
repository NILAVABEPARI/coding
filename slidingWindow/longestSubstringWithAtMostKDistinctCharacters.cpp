#include <bits/stdc++.h>
#using namespace std;

class Solution
{
public:
    int kDistinctChar(string &s, int k)
    {
        unordered_map<char, int> mp;
        int l = 0, r = 0, n = s.size(), maxi = 0;
        while (r < n)
        {
            mp[s[r]]++;
            while (mp.size() > k)
            {
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                    mp.erase(s[l]);
                l++;
            }
            maxi = max(maxi, r - l + 1);
            r++;
        }
        return maxi;
    }
};