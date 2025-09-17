#include <iostream>
using namespace std;

class BankAccount
{

public:
    string accountName;
    int Balance;
};

int main()
{
    BankAccount myAccount;

    myAccount.accountName = "Ali Shan";
    myAccount.Balance = 500;

    cout << "Name: " << myAccount.accountName << endl;
    cout << "Balance: " << myAccount.Balance;

    return 0;
}