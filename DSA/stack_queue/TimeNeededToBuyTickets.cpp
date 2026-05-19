#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int time = 0;
        for (int i = 0; i < tickets.size(); i++)
        {
            if (i <= k)
                time += min(tickets[k], tickets[i]);
            else
                time += min(tickets[k] - 1, tickets[i]);
        }
        return time;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {5, 1, 1, 1}; // {2, 3, 2};
    cout << "time required -- " << sol.timeRequiredToBuy(arr, 0);
    return 0;
}