#include <iostream>
using namespace std;

// Question # 1:
// Part 1:

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    for (int i = 4; i >= 0; i--)
    {
        cout << arr[i] << " \n";
    }
    return 0;
}

// Part 2 :

// int main()
// {
//     int arr[5];
//     cout << "Please enter elements for the array:" << endl;
//     for (int i = 0; i < 5; i++)
//     {
//         cout << "Element " << i << ": ";
//         cin >> arr[i];
//     }

//     arr[4] = 10;

//     arr[2] = 53;

//     for (int i = 0; i < 5; i++)
//     {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }