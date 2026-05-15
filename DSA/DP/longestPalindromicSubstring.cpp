#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // brute force --
    // bool isPalindrome(string s, int i, int j)
    // {
    //     while (i <= j)
    //     {
    //         if (s[i] != s[j])
    //             return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
    // string longestPalindrome(string s)
    // {
    //     int n = s.length(), maxi = 0;
    //     string ans = "";
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = i; j < n; j++)
    //         {
    //             int length = j - i + 1;
    //             if ((j - i + 1) > ans.length() && isPalindrome(s, i, j))
    //                 ans = s.substr(i, j - i + 1);
    //         }
    //     }
    //     return ans;
    // }

    // top down approach -- memoization
    bool solve(string &s, int l, int r, vector<vector<int>> &dp)
    {
        if (l >= r)
            return 1;
        if (dp[l][r] != -1)
            return dp[l][r];

        if (s[l] == s[r])
            return dp[l][r] = solve(s, l + 1, r - 1, dp);
        return dp[l][r] = 0;
    }
    string longestPalindrome(string s)
    {
        int n = s.length(), maxLen = 0, startInd = 0;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (j - i + 1 > maxLen && solve(s, i, j, dp))
                {
                    startInd = i;
                    maxLen = j - i + 1;
                }
            }
        }
        cout << "dp -- " << endl;
        for (auto &it : dp)
        {
            for (auto &i : it)
                cout
                    << i << " ";
            cout << endl;
        }
        return s.substr(startInd, maxLen);
    }
};

int main()
{
    Solution sol;
    // string s = "jrjnbctoqgzimtoklkxcknwmhiztomaofwwzjnhrijwkgmwwuazcowskjhitejnvtblqyepxispasrgvgzqlvrmvhxusiqqzzibcyhpnruhrgbzsmlsuacwptmzxuewnjzmwxbdzqyvsjzxiecsnkdibudtvthzlizralpaowsbakzconeuwwpsqynaxqmgngzpovauxsqgypinywwtmekzhhlzaeatbzryreuttgwfqmmpeywtvpssznkwhzuqewuqtfuflttjcxrhwexvtxjihunpywerkktbvlsyomkxuwrqqmbmzjbfytdddnkasmdyukawrzrnhdmaefzltddipcrhuchvdcoegamlfifzistnplqabtazunlelslicrkuuhosoyduhootlwsbtxautewkvnvlbtixkmxhngidxecehslqjpcdrtlqswmyghmwlttjecvbueswsixoxmymcepbmuwtzanmvujmalyghzkvtoxynyusbpzpolaplsgrunpfgdbbtvtkahqmmlbxzcfznvhxsiytlsxmmtqiudyjlnbkzvtbqdsknsrknsykqzucevgmmcoanilsyyklpbxqosoquolvytefhvozwtwcrmbnyijbammlzrgalrymyfpysbqpjwzirsfknnyseiujadovngogvptphuyzkrwgjqwdhtvgxnmxuheofplizpxijfytfabx";
    string s = "abcba";
    cout << "ans -- " << sol.longestPalindrome(s);
    return 0;
}