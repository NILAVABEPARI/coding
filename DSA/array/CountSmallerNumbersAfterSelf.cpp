#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &count, vector<pair<int, int>> &v, int left, int mid, int right)
    {
        vector<pair<int, int>> temp;
        int i = left, j = mid + 1, cnt = 0;
        while (i <= mid && j <= right)
        {
            // sorting in descending order
            if (v[i].first <= v[j].first)
                temp.push_back(v[j++]);
            else
            {
                count[v[i].second] += right - j + 1;
                temp.push_back(v[i++]);
            }
        }
        while (i <= mid)
            temp.push_back(v[j++]);
        while (j <= right)
            temp.push_back(v[j++]);
        for (int i = 0; i < temp.size(); i++)
            v[i + left] = temp[i];
    }
    void mergeSort(vector<int> &count, vector<pair<int, int>> &v, int left, int right)
    {
        if (left >= right)
            return;
        int mid = left + (right - left) / 2;
        mergeSort(count, v, left, mid);
        mergeSort(count, v, mid + 1, right);
        merge(count, v, left, mid, right);
    }
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
            v[i] = make_pair(nums[i], i);
        vector<int> count(n, 0);
        mergeSort(count, v, 0, n - 1);
        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {5, 2, 6, 1};
    vector<int> ans = sol.countSmaller(arr);
    cout << "smaller elements after self -- " << endl;
    for (auto &it : ans)
        cout << it << " ";
    return 0;
}