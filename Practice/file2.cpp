#include <iostream>
using namespace std;

const int MAX = 5;
int stackArr[MAX];
int top = -1;

void push(int x)
{

    if (top == MAX - 1)
    {
        cout << "Stack Overflow! Cannot push " << x << endl;
        return;
    }

    stackArr[++top] = x;

    cout << x << " pushed into the stack at index " << top << endl;
}

void display()
{
    if (top == -1)
    {
        cout << "Stack is empty!" << endl;
        return;
    }

    cout << "Current stack elements: ";
    for (int i = 0; i <= top; i++)
        cout << stackArr[i] << " ";
    cout << endl;
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    display();

    return 0;
}