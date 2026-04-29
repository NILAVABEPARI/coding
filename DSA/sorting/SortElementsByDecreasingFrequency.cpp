#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> sortByFreq(vector<int> &arr)
    {
        unordered_map<int, int> freq;
        for (auto it : arr)
            freq[it]++;

        vector<vector<int>> vec;
        for (auto it : freq)
            vec.push_back({it.first, it.second});

        // !! give & inside comparator to avoid copying vectors (&a and &b)
        // !! lambda expressions should always end with a ;
        auto comparator = [&](vector<int> &a, vector<int> &b)
        {
            if (a[1] != b[1])
                return a[1] > b[1];
            return a[0] < b[0];
        };

        sort(vec.begin(), vec.end(), comparator);

        vector<int> ans;
        for (auto it : vec)
        {
            for (int i = 0; i < it[1]; i++)
                ans.push_back(it[0]);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {5, 5, 4, 6, 5, 5, 6, 6, 4};
    vector<int> ans = sol.sortByFreq(arr);
    cout << "sorted array -- " << endl;
    for (auto it : ans)
        cout << it << " ";
    return 0;
}