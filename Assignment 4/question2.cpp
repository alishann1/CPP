#include <iostream>

using namespace std;

struct Node
{
    int token;
    Node *next;
};

class CustomerQueue
{
private:
    Node *front;
    Node *rear;

public:
    CustomerQueue()
    {
        front = nullptr;
        rear = nullptr;
    }

    void newToken(int tokenID)
    {
        Node *temp = new Node();
        temp->token = tokenID;
        temp->next = nullptr;

        if (front == nullptr)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }

        cout << "Action: New Token Generated" << endl;
        cout << ">> Output: Token " << tokenID << " has been enqueued." << endl;
    }

    void serveCustomer()
    {
        if (front == nullptr)
        {
            cout << "Action: Serve Customer" << endl;
            cout << ">> Error: Queue is empty! No customers to serve." << endl;
            return;
        }

        Node *temp = front;
        int servedToken = temp->token;

        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;

        cout << "Action: Serve Customer" << endl;
        cout << ">> Output: Serving customer with Token " << servedToken << " (Dequeued)." << endl;
    }

    ~CustomerQueue()
    {
        while (front != nullptr)
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main()
{
    CustomerQueue line;

    cout << "--- CUSTOMER SERVICE LINE STARTED ---\n"
         << endl;

    line.newToken(101);
    line.newToken(102);
    line.newToken(103);

    cout << endl;

    line.serveCustomer();
    line.serveCustomer();
    line.serveCustomer();

    line.serveCustomer();

    return 0;
}