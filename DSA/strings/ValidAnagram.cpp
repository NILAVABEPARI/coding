#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> mp;
        for (auto &it : s)
            mp[it]++;
        for (auto &it : t)
        {
            if (mp[it] != 0)
                mp[it]--;
            else
                return false;
        }
        return true;
    }
};