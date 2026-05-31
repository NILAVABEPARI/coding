#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MyStack
{
public:
    queue<int> q;
    MyStack() {}

    void push(int x)
    {
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        if (q.empty())
            return -1;
        int result = q.front();
        q.pop();
        return result;
    }

    int top() return q.empty() ? -1 : q.front();

    bool empty() return q.empty();
};