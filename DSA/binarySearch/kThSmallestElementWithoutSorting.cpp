#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int kthSmallest(vector<int> arr, int k)
    {
        int n = arr.size();
        int high = *max_element(arr.begin(), arr.end());
        int low = *min_element(arr.begin(), arr.end());
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int countLess = 0, countEqual = 0;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] < mid)
                    countLess++;
                else if (arr[i] == mid)
                    countEqual++;
            }

            if (countLess < k && (countLess + countEqual) == k)
                return mid;
            else if (countLess >= k)
                high = mid - 1;
            else if (countLess < k && (countLess + countEqual) < k)
                low = mid + 1;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    // !! there are no duplicates in the array
    // !! we can't use extra space and array can't be modified
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    cout << "kth smallest -- " << sol.kthSmallest(arr, 4);
    return 0;
}