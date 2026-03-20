#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
private:
    int *arr, front, back, currSize, maxSize;

public:
    MyQueue()
    {
        maxSize = 5000;
        arr = new int[maxSize];
        front = back = -1;
        currSize = 0;
    }
    void push(int x)
    {
        if (currSize == maxSize)
            return;
        if (currSize == 0)
        {
            front = 0;
            back = 0;
        }
        else
            back = (back + 1) % maxSize;
        arr[back] = x;
        currSize++;
    }
    int pop()
    {
        if (currSize == 0)
            return -1;
        int popped = arr[front];
        if (currSize == 1)
        {
            front = -1;
            back = -1;
        }
        else
            front = (front + 1) % maxSize;
        currSize--;
        return popped;
    }
};

int main()
{
    MyQueue *mq = new MyQueue();
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> nums;
    int num;
    while (ss >> num)
    {
        nums.push_back(num);
    }
    int n = nums.size();
    int i = 0;
    while (i < n)
    {
        int queryType = nums[i++];
        if (queryType == 1)
        {
            int a = nums[i++];
            mq->push(a);
        }
        else
        {
            cout << mq->pop() << " ";
        }
    }
    delete mq;
    return 0;
}
