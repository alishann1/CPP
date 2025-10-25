#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string url;
    Node *next;
    Node *prev;

    Node(string data)
    {
        this->url = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class BrowserHistory
{
private:
    Node *head;
    Node *current;

public:
    BrowserHistory()
    {
        head = nullptr;
        current = nullptr;
        cout << "Browser history simulation started." << endl;
    }

    void visit(string url)
    {
        Node *newNode = new Node(url);
        cout << "Visiting: " << url << endl;

        if (head == nullptr)
        {
            head = newNode;
            current = newNode;
        }
        else
        {
            if (current->next != nullptr)
            {
                Node *temp = current->next;
                while (temp != nullptr)
                {
                    Node *toDelete = temp;
                    temp = temp->next;
                    delete toDelete;
                }
            }

            current->next = newNode;
            newNode->prev = current;

            current = newNode;
        }
    }

    void showCurrent()
    {
        if (current != nullptr)
        {
            cout << "Current Page --> " << current->url << endl;
        }
        else
        {
            cout << "Browser history is empty. No current page." << endl;
        }
    }

    void back()
    {
        if (current != nullptr && current->prev != nullptr)
        {
            current = current->prev;
            cout << "Navigating back." << endl;
            showCurrent();
        }
        else
        {
            cout << "Cannot go back. You are at the beginning of the history." << endl;
        }
    }

    void forward()
    {
        if (current != nullptr && current->next != nullptr)
        {
            current = current->next;
            cout << "Navigating forward." << endl;
            showCurrent();
        }
        else
        {
            cout << "Cannot go forward. No forward history available." << endl;
        }
    }

    void showHistory()
    {
        cout << "\n--- Full Browser History ---" << endl;
        if (head == nullptr)
        {
            cout << "History is empty." << endl;
            return;
        }

        Node *temp = head;
        while (temp != nullptr)
        {
            cout << "- " << temp->url;
            if (temp == current)
            {
                cout << "  <-- CURRENT";
            }
            cout << endl;
            temp = temp->next;
        }
        cout << "---------------------------\n"
             << endl;
    }
};

int main()
{
    BrowserHistory myBrowser;

    cout << "\n[STEP 1] Visiting a few websites..." << endl;
    myBrowser.visit("google.com");
    myBrowser.visit("youtube.com");
    myBrowser.visit("github.com");
    myBrowser.showHistory();

    cout << "\n[STEP 2] Using the 'back' button twice..." << endl;
    myBrowser.back();
    myBrowser.back();
    myBrowser.showHistory();

    cout << "\n[STEP 3] Using the 'forward' button..." << endl;
    myBrowser.forward();
    myBrowser.showHistory();

    cout << "\n[STEP 4] Visiting a new site. This will erase the forward history ('github.com')..." << endl;
    myBrowser.visit("linkedin.com");
    myBrowser.showHistory();

    cout << "\n[STEP 5] Trying to go forward again (should fail)..." << endl;
    myBrowser.forward();

    return 0;
}