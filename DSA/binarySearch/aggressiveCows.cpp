#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int countCows(vector<int> &arr, int dist)
    {
        int i = 1, n = arr.size(), cnt = 1, start = arr[0];
        while (i < n)
        {
            if (arr[i] - start >= dist)
            {
                cnt++;
                start = arr[i];
            }
            i++;
        }
        return cnt;
    }

public:
    int aggressiveCows(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size(), low = 1, high = arr[n - 1] - arr[0];
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (countCows(arr, mid) >= k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};

int main()
{
    vector<int> arr = {0, 3, 4, 7, 10, 9};
    int k = 4;
    Solution sol;
    cout << "maximum distance -- " << sol.aggressiveCows(arr, k);
    return 0;
}