#include <iostream>

using namespace std;

// Step 1: Create a Node class
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Step 2: Create a myQueue class
class myQueue
{
private:
    Node *front;
    Node *rear;
    int currSize;

public:
    myQueue()
    {
        front = nullptr;
        rear = nullptr;
        currSize = 0;
    }

    bool isEmpty()
    {
        return currSize == 0;
    }
};

int main()
{
    myQueue q;

    if (q.isEmpty())
    {
        cout << "The queue is empty." << endl;
    }
    else
    {
        cout << "The queue is not empty." << endl;
    }

    return 0;
}