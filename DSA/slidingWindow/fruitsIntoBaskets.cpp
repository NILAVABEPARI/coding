#include <bits/stdc++.h>
#using namespace std;

class Solution
{
public:
    int totalFruits(vector<int> &fruits)
    {
        map<int, int> mp;
        int n = fruits.size(), l = 0, r = 0, cnt = 0;
        while (r < n)
        {
            mp[fruits[r]]++;
            while (mp.size() > 2)
            {
                mp[fruits[l]]--;
                if (mp.count(fruits[l]) == 0)
                    mp.erase(fruits[l]);
                l++;
            }
            cnt = max(cnt, r - l + 1);
        }
        return cnt;
    }
}