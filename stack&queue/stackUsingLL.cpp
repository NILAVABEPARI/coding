#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node()
    {
        val = 0;
        next = NULL;
    }
    Node(int _val)
    {
        val = val;
        next = NULL;
    }
};

class MyStack
{
private:
    Node *top;

public:
    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = top;
        top = temp;
    }
    int pop()
    {
        Node *temp = top;
        top = top->next;
        int x = temp->val;
        delete temp;
        return x;
    }
};

int main()
{
    return 0;
}