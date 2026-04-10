#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ArrayStack
{
private:
    int *stackArray;
    int capacity;
    int topIndex;

public:
    // constructor
    ArrayStack(int size = 1000)
    {
        cout << "stack is created of size -- " << size << endl;
        capacity = size;
        stackArray = new int[size];
        topIndex = -1;
    }

    // Destructor
    ~ArrayStack()
    {
        cout << "stack is being deleted" << endl;
        delete[] stackArray;
    }

    void push(int x)
    {
        if (topIndex >= capacity - 1)
        {
            cout << "Stack overflow";
            return;
        }
        stackArray[++topIndex] = x;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty";
            return -1;
        }
        return stackArray[topIndex--];
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty";
            return -1;
        }
        return stackArray[topIndex];
    }

    bool isEmpty()
    {
        return topIndex == -1;
    }
};

int main()
{
    ArrayStack stack;
    vector<string> commands = {"ArrayStack", "push", "push", "top", "pop", "isEmpty"};
    vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

    for (size_t i = 0; i < commands.size(); ++i)
    {
        if (commands[i] == "push")
        {
            stack.push(inputs[i][0]);
            cout << "null ";
        }
        else if (commands[i] == "pop")
            cout << stack.pop() << " ";
        else if (commands[i] == "top")
            cout << stack.top() << " ";
        else if (commands[i] == "isEmpty")
            cout << (stack.isEmpty() ? "true" : "false") << " ";
        else if (commands[i] == "ArrayStack")
            cout << "null ";
    }
    cout << endl;

    return 0;
}
