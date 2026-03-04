#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void heapifyDown(vector<int> &nums, int ind)
    {
        int smallestInd = ind, n = nums.size();
        int leftInd = 2 * ind + 1, rightInd = 2 * ind + 2;

        if (leftInd < n && nums[leftInd] < nums[smallestInd])
            smallestInd = leftInd;
        if (rightInd < n && nums[rightInd] < nums[smallestInd])
            smallestInd = rightInd;

        if (smallestInd != ind)
        {
            swap(nums[ind], nums[smallestInd]);
            heapifyDown(nums, smallestInd);
        }
    }
    void heapifyUp(vector<int> &nums, int ind)
    {
        int parentInd = (ind - 1) / 2;
        if (ind > 0 && nums[parentInd] > nums[ind])
        {
            swap(nums[parentInd], nums[ind]);
            heapifyUp(nums, parentInd);
        }
    }

public:
    void heapify(vector<int> &nums, int ind, int val)
    {
        if (nums[ind] > val)
        {
            nums[ind] = val;
            heapifyDown(nums, ind);
        }
        else
        {
            nums[ind] = val;
            heapifyUp(nums, ind);
        }
    }
};