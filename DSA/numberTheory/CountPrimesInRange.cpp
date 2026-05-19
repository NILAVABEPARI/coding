#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> primesInRange(vector<vector<int>> &queries)
    {
        int maxVal = 0;
        for (auto &it : queries)
            maxVal = max(maxVal, it[1]);
        vector<int> sieve(maxVal + 1, 1);
        sieve[0] = 0;
        sieve[1] = 0;
        // 1. create the sieve array
        for (int i = 2; i * i <= maxVal; i++)
        {
            if (sieve[i] == 1)
            {
                for (int j = i * i; j <= maxVal; j += i)
                    sieve[j] = 0;
            }
        }

        // 2. create the prefix sum
        for (int i = 1; i <= maxVal; i++)
            sieve[i] += sieve[i - 1];

        vector<int> ans;
        for (auto &it : queries)
        {
            int low = it[0], high = it[1];
            if (low == 0)
                ans.push_back(sieve[high]);
            else
                ans.push_back(sieve[high] - sieve[low - 1]);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> queries = {{1, 7}, {3, 7}};
    vector<int> ans = sol.primesInRange(queries);
    for (auto &it : ans)
        cout << it << " ";
    return 0;
}