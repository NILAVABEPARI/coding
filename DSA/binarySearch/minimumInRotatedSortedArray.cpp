#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &arr)
    {
        int mini = INT_MAX, low = 0, high = arr.size() - 1;
        while (low <= high)
        {
            int mid = low + ((high - low) / 2);
            if (arr[low] <= arr[mid])
            {
                mini = min(mini, arr[low]);
                low = mid + 1;
            }
            else if ()
            {
                mini = min(mini, arr[mid]);
                high = mid - 1;
            }
        }
        return mini;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {4, 5, 6, 7, -7, 1, 2, 3};
    cout << "smallest element -- " << sol.findMin(arr);
    return 0;
}