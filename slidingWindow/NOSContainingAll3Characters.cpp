#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        // brute force --
        // int cnt = 0;
        // for (int i = 0; i < s.length(); i++)
        // {
        //     int hash[3] = {0};
        //     for (int j = i; j < s.length(); j++)
        //     {
        //         hash[s[j] - 'a'] = 1;
        //         if (hash[0] + hash[1] + hash[2] == 3)
        //             cnt++;
        //     }
        // }
        // return cnt;

        // optimal
        int cnt = 0, n = s.length();
        int lastSeen[3] = {-1, -1, -1};
        for (int i = 0; i < s.size(); ++i)
        {
            lastSeen[s[i] - 'a'] = i;
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
                cnt += 1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
        }
        return cnt;
    }
};

int main()
{
    return 0;
}