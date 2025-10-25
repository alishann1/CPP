#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x, pos;
    cout << "Enter element to insert: ";
    cin >> x;
    cout << "Enter position (0-based index): ";
    cin >> pos;

    int *newArr = new int[n + 1];

    for (int i = 0; i < pos; i++)
    {
        newArr[i] = arr[i];
    }

    newArr[pos] = x;

    for (int i = pos; i < n; i++)
    {
        newArr[i + 1] = arr[i];
    }

    cout << "Updated array: ";
    for (int i = 0; i < n + 1; i++)
    {
        cout << newArr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] newArr;

    return 0;
}
