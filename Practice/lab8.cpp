#include <iostream>

using namespace std;

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

    void enqueue(int val)
    {
        Node *newNode = new Node(val);

        if (isEmpty())
        {
            front = rear = newNode;
        }

        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        currSize++;
        cout << val << " enqueued to queue\n";
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        Node *temp = front;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    myQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Current Queue: ";
    q.display();

    return 0;
}