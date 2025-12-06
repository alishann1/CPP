#include <iostream>
#include <queue> // Required for Level Order Traversal

using namespace std;

// 1. Define the Node structure
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

// 2. Define the Contact Directory Class (BST)
class ContactDirectory
{
private:
    Node *root;

    // --- Private Helper Functions (Recursion) ---

    // Recursive Insert
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
        // Duplicate keys are ignored in this implementation
        return node;
    }

    // Recursive Search
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

    // Recursive Traversals
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
    // Constructor
    ContactDirectory()
    {
        root = nullptr;
    }

    // --- Requirement 1: Insert a New Contact ---
    void addContact(long long key)
    {
        root = insert(root, key);
        cout << "Contact " << key << " has been added to the directory" << endl;
    }

    // --- Requirement 2: Search for a Contact ---
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

    // --- Requirement 3: Display Traversals ---

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

    // Level Order requires a Queue (Iterative approach)
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

// Main function to test the requirements
int main()
{
    ContactDirectory dir;

    // 1. Insert Contacts
    cout << "--- Adding Contacts ---" << endl;
    dir.addContact(4165551212); // Root
    dir.addContact(3001234567); // Left child (smaller)
    dir.addContact(5009876543); // Right child (larger)
    dir.addContact(3125550000);
    dir.addContact(4165559999);

    cout << "\n--- Searching Contacts ---" << endl;
    // 2. Search Success
    dir.findContact(4165551212);
    // 2. Search Failure
    dir.findContact(9999999999);

    // 3. Display all traversals
    dir.displayTraversals();

    return 0;
}