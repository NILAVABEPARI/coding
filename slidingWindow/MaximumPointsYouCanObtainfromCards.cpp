#include <bits/stdc++.h>
#using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &cardScore, int k)
    {
        int n = cardScore.size(), sum = 0;
        if (k <= 0)
            return 0;
        for (int i = 0; i < k; i++)
            sum += cardScore[i];
        int l = k - 1, r = n - 1, maxSum = sum;
        while (l >= 0)
        {
            sum = sum - cardScore[l--] + cardScore[r--];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};