#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void push(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << value << " pushed to stack.\n";
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! Cannot pop.\n";
            return;
        }
        Node *temp = top;
        cout << "Popped: " << top->data << endl;
        top = top->next;
        delete temp;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
            return -1;
        }
        return top->data;
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element is: " << s.peek() << endl;

    s.pop();
    s.pop();

    if (s.isEmpty())
        cout << "Stack is empty.\n";
    else
        cout << "Stack is not empty.\n";

    return 0;
}
