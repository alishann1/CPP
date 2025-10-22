#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head; // pointer to the first node

public:
    // Constructor: initially empty listb
    LinkedList()
    {
        head = nullptr;
    }

    // Insert a new node at the end
    void insert(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr)
        { // empty list
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next; // move forward
            }
            temp->next = newNode;
        }
    }

    // Display all elements
    void display()
    {
        Node *temp = head;
        cout << "List: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next; // move to next node
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    list.display(); // List: 10 20 30 40

    return 0;
}