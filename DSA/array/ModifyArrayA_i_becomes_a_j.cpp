#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // !! important concept to store 2 values in a single index
    // arr[i] = old_value + new_value * n
    // new_value = arr[i] / n
    // old_value = arr[i] % n
    void rearrange(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
            arr[arr[i] % n] += n * i;
        for (auto &it : arr)
            it /= n;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {2, 0, 1, 4, 5, 3};
    sol.rearrange(arr);
    for (auto &it : arr)
        cout << it << " ";
    return 0;
}