#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Comparator
{
    const bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first != b.first)
            return a.first > b.first;
        else
            return a.second > b.second;
    }
};

class Solution
{
private:
    int countOnes(vector<int> &row)
    {
        int l = 0, h = row.size() - 1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (row[mid] == 0)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }

public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        // count ones, index
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> pq;
        for (int i = 0; i < mat.size(); i++)
        {
            int ones = countOnes(mat[i]);
            pq.push({ones, i});
        }
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }

    // using simple sort -- no PQ required
    vector<int> kWeakestRowsSimple(vector<vector<int>> &mat, int k)
    {
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++)
            mat[i].push_back(i);
        vector<int> ans;
        sort(mat.begin(), mat.end());
        for (int i = 0; i < k; i++)
            ans.push_back(mat[i][m]);
        return ans;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 1, 0, 0, 0}, {1, 1, 1, 1, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 0, 0}, {1, 1, 1, 1, 1}};
    int k = 3;
    Solution sol;
    vector<int> ans = sol.kWeakestRows(matrix, k);
    cout << "kth weakest rows -- " << endl;
    for (auto &it : ans)
        cout << it << " ";
    return 0;
}