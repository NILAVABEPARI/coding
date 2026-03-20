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

public:
    void buildMinHeap(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = (n / 2 - 1); i >= 0; i--)
            heapifyDown(nums, i);
    }
};