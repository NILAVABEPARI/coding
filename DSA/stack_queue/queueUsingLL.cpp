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
        val = _val;
        next = NULL;
    }
};

class MyQueue
{
private:
    Node *front, *end;

public:
    MyQueue()
    {
        front = end = NULL;
    }
    void push(int x)
    {
        Node *temp = new Node(x);
        if (!front)
        {
            front = end = temp;
        }
        else
        {
            end->next = temp;
            end = temp;
        }
    }
    int pop()
    {
        if (!front)
            return -1;
        Node *temp = front;
        front = front->next;
        int val = temp->val;
        delete temp;
        return val;
    }
};

struct Node
{
    int val;
    Node *next;
    Node()
    {
        val = -1;
        next = NULL;
    }
    Node(int x)
    {
        val = x;
        next = NULL;
    }
};

class LinkedListQueue2
{
    Node *head, *curr;

public:
    LinkedListQueue()
    {
        head = curr = NULL;
    }

    void push(int x)
    {
        if (!head)
        {
            head = new Node(x);
            curr = head;
        }
        else
        {
            Node *temp = new Node(x);
            curr->next = temp;
            curr = temp;
        }
    }

    int pop()
    {
        if (!head)
            return -1;
        Node *temp = head;
        head = head->next;
        int x = temp->val;
        delete temp;
        return x;
    }

    int peek()
    {
        if (!head)
            return -1;
        return head->val;
    }

    bool isEmpty()
    {
        return head == NULL;
    }
};