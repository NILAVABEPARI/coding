#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int gcd(int a, int b)
    {
        while (b)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    int gcdRecur(int a, int b)
    {
        if (b == 0)
            return a;
        return gcdRecur(b, a % b);
    }
    vector<int> lcmAndGcd(int a, int b)
    {
        int gcd = gcdRecur(a, b);
        return {(a / gcd) * b, gcd};
    }
};

int main()
{
    Solution sol;
    vector<int> ans = sol.lcmAndGcd(18, 12);
    cout << "ans -- " << ans[0] << " " << ans[1];
    return 0;
}