#include <iostream>
using namespace std;

class Solution
{
public:
    int countLessOrEqual(int m, int n, int x)
    {
        int ans = 0;
        for (int i = 1; i <= m; i++)
            ans += min(n, x / i);
        return ans;
    }
    int findKthNumber(int m, int n, int k)
    {
        int low = 1, high = m * n, ans;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (countLessOrEqual(m, n, mid) < k)
                low = mid + 1;
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    cout << "kth number -- " << sol.findKthNumber(3, 3, 7);
    return 0;
}