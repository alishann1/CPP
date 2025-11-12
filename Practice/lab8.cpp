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
        return front == nullptr;
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
        cout << val << " enqueued.\n";
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow\n";
            return -1;
        }
        Node *temp = front;
        int dequeuedValue = temp->data;
        front = front->next;
        delete temp;
        currSize--;

        if (front == nullptr)
        {
            rear = nullptr;
        }
        return dequeuedValue;
    }
};

int main()
{
    myQueue q;
    q.enqueue(10);
    q.enqueue(20);

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    q.dequeue();

    return 0;
}