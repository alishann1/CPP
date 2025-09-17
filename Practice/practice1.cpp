#include <iostream>
using namespace std;

int main()
{

    string food = "Pizza";
    string &meal = food;

    cout << &food;
    // cout << food << '\n';
    // cout << meal << '\n';

    // meal = "Pasta";
    // cout << meal << '\n';
    // cout << food;
    return 0;
}