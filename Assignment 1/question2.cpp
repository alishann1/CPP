#include <iostream>
using namespace std;

// Question # 2:
int arraySum(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = arraySum(arr, size);
    double average = 0;

    if (size == 0)
    {
        average = 0.0;
    }
    else
    {
        static_cast<double>(sum) / size;
    }

    cout << "Sum: " << sum << endl;
    cout << "Size: " << size;

    return 0;
}