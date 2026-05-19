#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution
{
public:
    int SumOfKSubarray(vector<int> &arr, int N, int k)
    {
        deque<int> descending, ascending;
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            // descending deque;
            if (!descending.empty() && descending.front() <= i - k)
                descending.pop_front();
            while (!descending.empty() && arr[descending.back()] < arr[i])
                descending.pop_back();
            descending.push_back(i);

            // ascending deque;
            if (!ascending.empty() && ascending.front() <= i - k)
                ascending.pop_front();
            while (!ascending.empty() && arr[ascending.back()] > arr[i])
                ascending.pop_back();
            ascending.push_back(i);
            if (i >= k - 1)
                sum += arr[ascending.front()] + arr[descending.front()];
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {2, 5, -1, 7, -3, -1, -2};
    cout << "sum -- " << sol.SumOfKSubarray(arr, arr.size(), 4);
    return 0;
}