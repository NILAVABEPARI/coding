#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        for (int i = 0; i < tasks.size(); i++)
            tasks[i].push_back(i);      // append the index to each task
        sort(begin(tasks), end(tasks)); // sort the input array so that we can take the tasks of small enqueueTime first

        // min heap of tasks, sorted first by processing time then by index.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans;
        // `currentTime` is the current time, `i` is the read pointer
        int i = 0, n = tasks.size(), currentTime = tasks[0][0];

        // stop the loop when we exhausted the input array and the tasks in the heap.
        while (i < n || !pq.empty())
        {
            // nothing in the heap? try updating the current time using the processing time of the next task in array
            if (pq.empty())
            {
                currentTime = tasks[i][0];
                continue;
            }
            // push all the tasks in the array whose enqueueTime <= currentTime into the heap
            while (i < n && tasks[i][0] <= currentTime)
            {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            // handle this task and increase the current time by the processingTime
            int index = pq.top().second;
            currentTime += pq.top().first;
            pq.pop();
            ans.push_back(index);
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> nums = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};
    Solution sol;
    vector<int> ans = sol.getOrder(nums);
    cout << "minimum total  -- ";
    for (auto &it : ans)
        cout << it << " ";
    return 0;
}