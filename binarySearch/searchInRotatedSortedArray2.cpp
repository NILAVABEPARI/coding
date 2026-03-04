#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool search(vector<int> arr, int target)
    {
        int l = 0, r = arr.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (target == arr[mid])
                return true;
            else if (arr[l] == arr[mid] && arr[mid] == arr[r])
            {
                l++;
                r--;
            }
            else if (arr[l] <= arr[mid])
            {
                if (arr[l] <= target && target <= arr[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else
            {
                if (arr[mid] <= target && target <= arr[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> arr(2, 1, 5, 4, 3, 0, 0);
    int target;
    cin >> target;
    cout << s.search(arr, target);
    return 0;
}