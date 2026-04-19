#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // my method
    // string reverseEqn(string s)
    // {
    //     string ans = "";
    //     for (int i = s.length() - 1; i >= 0; i--)
    //     {
    //         string dig = "";
    //         while (i >= 0 && s[i] != '-' && s[i] != '+' && s[i] != '*' && s[i] != '/')
    //             dig += s[i--];
    //         reverse(dig.begin(), dig.end());
    //         ans += dig;
    //         if (i >= 0)
    //             ans += s[i];
    //     }
    //     return ans;
    // }

    // optimal
    string reverseEqn(string s)
    {
        string num = "";
        vector<string> tokens;
        for (char c : s)
        {
            if (isdigit(c))
            {
                num += c;
            }
            else
            {
                tokens.push_back(num);
                num = "";
                tokens.push_back(string(1, c));
            }
        }
        // add the last number
        tokens.push_back(num);

        reverse(tokens.begin(), tokens.end());
        string ans = "";
        for (auto it : tokens)
        {
            ans += it;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "20-3+5*2";
    cout << "reverse -- " << sol.reverseEqn(s);
    return 0;
}