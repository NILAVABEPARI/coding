#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        unordered_map<char, int> m1, m2;
        vector<int> ans;
        int n = s.length(), m = p.length();
        for (int i = 0; i < m; i++)
        {
            m1[s[i]]++;
            m2[s[i]]++;
        }
        if (m1 == m2)
            ans.push_back(0);
        for (int i = m; i < n; i++)
        {
            m1[s[i - m]]--;
            if (m1[s[i - m]] == 0)
                m1.erase(s[i - m]);
            m1[s[i]]++;
            if (m1 == m2)
                ans.push_back(i - m + 1);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "abab", p = "ab";
    vector<int> ans = sol.findAnagrams(s, p);
    cout << "ans -- ";
    for (auto &it : ans)
        cout
            << it << " ";
    return 0;
}