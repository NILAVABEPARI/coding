#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int left = 0, right = 0, i = 0, n = s.length();
        reverse(s.begin(), s.end());
        while (i < n)
        {
            while (i < n && s[i] == ' ')
                i++;
            if (i == n)
                break;
            while (i < n && s[i] != ' ')
                s[right++] = s[i++];
            reverse(s.begin() + left, s.begin() + right);
            s[right++] = ' ';
            left = right;
            i++;
        }
        s.resize(right - 1);
        return s;
    }
};

int main()
{
    string s = "a good   example";
    Solution sol;
    cout << "reversed string -- " << sol.reverseWords(s);
    return 0;
}