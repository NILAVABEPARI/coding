#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    MinStack()
    {
    }

    void push(int value)
    {
    }

    void pop()
    {
    }

    int top()
    {
    }

    int getMin()
    {
    }
};

int main()
{
    MinStack s;

    // Function calls
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout << s.getMin() << " ";
    s.pop();
    cout << s.top() << " ";
    s.pop();
    cout << s.getMin();

    return 0;
}