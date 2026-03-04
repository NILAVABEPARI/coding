#include <bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    int arr[1000];
    int top;

public:
    MyStack()
    {
        top = -1;
    }
    void push(int);
    int pop();
};

void MyStack ::push(int x)
{
    if (top >= 999)
        return;
    arr[++top] = x;
}

int MyStack ::pop()
{
    if (top == -1)
        return -1;
    return arr[top--];
}

int main()
{
    MyStack *ms = new MyStack();
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
            ms->push(a);
        }
        else
        {
            cout << ms->pop() << " ";
        }
    }
    delete ms;
    return 0;
}
