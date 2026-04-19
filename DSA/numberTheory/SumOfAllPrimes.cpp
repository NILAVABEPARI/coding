#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int prime_Sum(int n)
    {
        vector<int> sieve(n + 1, 1);
        sieve[0] = 0;
        sieve[1] = 0;

        for (int i = 2; i * i <= n; i++)
        {
            if (sieve[i] == 1)
            {
                for (int j = i * i; j <= n; j += i)
                {
                    sieve[j] = 0;
                }
            }
        }
        int sum = 0;
        for (int i = 2; i <= n; i++)
        {
            if (sieve[i])
                sum += i;
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    cout << sol.prime_Sum(15);
    return 0;
}