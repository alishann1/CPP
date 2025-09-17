#include <iostream>
using namespace std;

class BankAccount
{

public:
    string accountName;
    int Balance;

    void display()
    {

        cout << "Name: " << accountName << endl;
        cout << "Balance: " << Balance;
    }
};

int main()
{
    BankAccount myAccount;
    myAccount.accountName = "Ali Shan";
    myAccount.Balance = 500;
    myAccount.display();

    return 0;
}