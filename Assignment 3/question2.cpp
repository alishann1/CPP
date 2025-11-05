#include <iostream>
#include <string>

using namespace std;

struct Coach
{
    int number;
    Coach *next;
    Coach *prev;

    Coach(int num)
    {
        this->number = num;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class Train
{
private:
    Coach *head;
    Coach *tail;

public:
    Train()
    {
        head = nullptr;
        tail = nullptr;
    }

    void addCoachFront(int num)
    {
        Coach *newCoach = new Coach(num);
        cout << "Adding Coach #" << num << " to the front." << endl;

        if (head == nullptr)
        {
            head = newCoach;
            tail = newCoach;
        }
        else
        {
            newCoach->next = head;
            head->prev = newCoach;
            head = newCoach;
        }
    }

    void addCoachEnd(int num)
    {
        Coach *newCoach = new Coach(num);
        cout << "Adding Coach #" << num << " to the end." << endl;

        if (head == nullptr)
        {
            head = newCoach;
            tail = newCoach;
        }
        else
        {
            tail->next = newCoach;
            newCoach->prev = tail;
            tail = newCoach;
        }
    }

    void displayForward()
    {
        cout << "\nTrain (Forward): [Head] ";
        if (head == nullptr)
        {
            cout << "(Empty)";
        }

        Coach *temp = head;
        while (temp != nullptr)
        {
            cout << "<- " << temp->number << " ->";
            temp = temp->next;
        }
        cout << " [Tail]" << endl;
    }

    void displayBackward()
    {
        cout << "Train (Backward): [Tail] ";
        if (tail == nullptr)
        {
            cout << "(Empty)";
        }

        Coach *temp = tail;
        while (temp != nullptr)
        {
            cout << "<- " << temp->number << " ->";
            temp = temp->prev;
        }
        cout << " [Head]" << endl;
    }

    int countCoaches()
    {
        int count = 0;
        Coach *temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void removeCoach(int num)
    {
        Coach *temp = head;
        while (temp != nullptr && temp->number != num)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Coach #" << num << " not found." << endl;
            return;
        }

        cout << "\nRemoving Coach #" << num << "..." << endl;

        if (temp == head)
        {
            head = temp->next;
        }

        if (temp == tail)
        {
            tail = temp->prev;
        }

        if (temp->prev != nullptr)
        {
            temp->prev->next = temp->next;
        }

        if (temp->next != nullptr)
        {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }
};

int main()
{
    Train myTrain;

    myTrain.addCoachEnd(20);
    myTrain.addCoachEnd(30);
    myTrain.addCoachFront(10);
    myTrain.addCoachEnd(40);

    myTrain.displayForward();
    myTrain.displayBackward();
    cout << "\nTotal coaches: " << myTrain.countCoaches() << endl;

    myTrain.removeCoach(30);
    myTrain.displayForward();

    myTrain.removeCoach(10);
    myTrain.displayForward();

    myTrain.removeCoach(40);
    myTrain.displayForward();

    myTrain.removeCoach(20);
    myTrain.displayForward();

    cout << "\nTotal coaches after removal: " << myTrain.countCoaches() << endl;

    return 0;
}