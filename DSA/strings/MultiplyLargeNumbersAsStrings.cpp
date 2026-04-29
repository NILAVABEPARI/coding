#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string multiplyStrings(string s1, string s2)
    {
        int n = s1.size(), m = s2.size();
        if (n == 0 || m == 0)
            return "0";
        int nn = 1, mm = 1;
        if (s1[0] == '-')
            nn = -1;
        if (s2[0] == '-')
            mm = -1;
        bool isNegative = nn * mm;

        vector<int> arr(n + m, 0);
        int i1 = 0, i2 = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s1[i] == '-')
                continue;
            int n1 = s1[i] - '0';
            int carry = 0;
            i2 = 0;

            for (int j = m - 1; j >= 0; j--)
            {
                if (s2[j] == '-')
                    continue;
                int n2 = s2[j] - '0';

                int sum = (n1 * n2) + arr[i1 + i2] + carry;
                carry = sum / 10;
                arr[i1 + i2] = sum % 10;
                i2++;
            }
            if (carry > 0)
                arr[i1 + i2] += carry;
            i1++;
        }

        // remove 0's from the right
        int z = arr.size() - 1;
        while (z >= 0 && arr[z] == 0)
            z--;

        if (z == -1)
            return "0";

        string ans = "";
        while (z >= 0)
            ans += to_string(arr[z--]);
        return isNegative == -1 ? "-" + ans : ans;
    }
};

int main()
{
    Solution sol;
    string s1 = "514", s2 = "267";
    cout << "multiplied string -- " << sol.multiplyStrings(s1, s2);
    return 0;
}