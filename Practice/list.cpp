#include <iostream>
using namespace std;

class List
{

private:
    int arr[10];
    int size;
    int cursor;

public:
    List()
    {
        size = 0;
        cursor = -1;
    }

    void add(int value)
    {
        for (int i = size; i < size + 1; i++)
        {
            arr[i] = value;
        }
        size++;
    }

    void display()
    {
        cout << "List elements: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    List myList;

    myList.add(10);
    myList.add(20);
    myList.add(30);

    myList.display();

    return 0;
}
