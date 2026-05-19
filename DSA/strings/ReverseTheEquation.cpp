#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string reverseEqn(string s)
    {
        vector<string> tokens;
        string temp = "";
        for (auto &ch : s)
        {
            if (isdigit(ch))
                temp += ch;
            else
            {
                tokens.push_back(temp);
                temp = "";
                tokens.push_back(string(1, ch));
            }
        }
        tokens.push_back(temp);
        reverse(tokens.begin(), tokens.end());
        string ans = "";
        for (auto &it : tokens)
            ans += it;
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "20-3+5*2";
    cout << sol.reverseEqn(s);
    return 0;
}