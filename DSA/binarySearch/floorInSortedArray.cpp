#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findFloor(vector<int> &v, int x)
    {
        int n = v.size(), l = 0, h = n - 1, ans = -1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (v[mid] == x)
                return mid;
            else if (v[mid] < x)
            {
                ans = mid;
                l = mid + 1;
            }
            else
                h = mid + 1;
        }
        return ans;
    }
};

int main()
{
    // Solution s;
    return 0;
}