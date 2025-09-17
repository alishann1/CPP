#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x, pos;
    cin >> x >> pos;

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

    for (int i = 0; i < n + 1; i++)
    {
        cout << newArr[i] << " ";
    }

    delete[] arr;
    delete[] newArr;

    return 0;
}
