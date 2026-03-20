#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &arr)
    {
        int mini = INT_MAX;
        int l = 0, h = arr.size() - 1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (arr[l] <= arr[mid])
            {
                mini = min(mini, arr[l]);
                l = mid + 1;
            }
            else
            {
                mini = min(mini, arr[mid]);
                h = mid - 1;
            }
        }
        return mini;
    }
}

int
main()
{

    return 0;
}