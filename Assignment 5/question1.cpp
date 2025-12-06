#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    long long phoneNumber;
    Node *left;
    Node *right;

    Node(long long num)
    {
        phoneNumber = num;
        left = nullptr;
        right = nullptr;
    }
};

class ContactDirectory
{
private:
    Node *root;

    Node *insert(Node *node, long long key)
    {
        if (node == nullptr)
        {
            return new Node(key);
        }
        if (key < node->phoneNumber)
        {
            node->left = insert(node->left, key);
        }
        else if (key > node->phoneNumber)
        {
            node->right = insert(node->right, key);
        }

        return node;
    }

    Node *search(Node *node, long long key)
    {
        if (node == nullptr || node->phoneNumber == key)
        {
            return node;
        }
        if (key < node->phoneNumber)
        {
            return search(node->left, key);
        }
        return search(node->right, key);
    }

    void inorder(Node *node)
    {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->phoneNumber << " ";
        inorder(node->right);
    }

    void preorder(Node *node)
    {
        if (node == nullptr)
            return;
        cout << node->phoneNumber << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node *node)
    {
        if (node == nullptr)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->phoneNumber << " ";
    }

public:
    ContactDirectory()
    {
        root = nullptr;
    }

    void addContact(long long key)
    {
        root = insert(root, key);
        cout << "Contact " << key << " has been added to the directory" << endl;
    }

    void findContact(long long key)
    {
        Node *result = search(root, key);
        if (result != nullptr)
        {
            cout << "Contact " << key << " is in the directory." << endl;
        }
        else
        {
            cout << "Contact " << key << " not found." << endl;
        }
    }

    void displayTraversals()
    {
        cout << "\n--- Directory Displays ---" << endl;

        cout << "a. Inorder Traversal (Sorted): ";
        inorder(root);
        cout << endl;

        cout << "b. Preorder Traversal: ";
        preorder(root);
        cout << endl;

        cout << "c. Postorder Traversal: ";
        postorder(root);
        cout << endl;

        cout << "d. Level Order Traversal: ";
        displayLevelOrder();
        cout << endl;
    }

    void displayLevelOrder()
    {
        if (root == nullptr)
            return;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();

            cout << current->phoneNumber << " ";

            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
    }
};

int main()
{
    ContactDirectory dir;

    cout << "--- Adding Contacts ---" << endl;
    dir.addContact(4165551212);
    dir.addContact(3001234567);
    dir.addContact(5009876543);
    dir.addContact(3125550000);
    dir.addContact(4165559999);

    cout << "\n--- Searching Contacts ---" << endl;
    dir.findContact(4165551212);
    dir.findContact(9999999999);
    dir.displayTraversals();

    return 0;
}