#include <iostream>
using namespace std;

void findMaxMin(int arr[], int n)
{
    int maxVal = arr[0];
    int minVal = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal)
            maxVal = arr[i];
        if (arr[i] < minVal)
            minVal = arr[i];
    }

    cout << "Maximum value: " << maxVal << endl;
    cout << "Minimum value: " << minVal << endl;
}

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

    findMaxMin(arr, n);

    delete[] arr;

    return 0;
}
