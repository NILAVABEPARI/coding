#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> nextPermutation(vector<int> &arr)
    {
        int n = arr.size(), ind = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] < arr[i + 1])
            {
                ind = i;
                break;
            }
        }
        if (ind == -1)
        {
            reverse(arr.begin(), arr.end());
            return arr;
        }
        for (int i = n - 1; i > ind; i--)
        {
            if (arr[i] > arr[ind])
            {
                swap(arr[i], arr[ind]);
                break;
            }
        }
        reverse(arr.begin() + ind + 1, arr.end());
        return arr;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {2, 1, 5, 4, 3, 0, 0};
    vector<int> ans = s.nextPermutation(arr);
    cout << "next permutation -- " << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}