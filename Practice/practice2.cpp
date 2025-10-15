#include <iostream>
using namespace std;

class Human
{
public:
    string name;
    string occupation;
    int age;

    void eat()
    {
        cout << "The human is eating \n";
    }

    void sleep()
    {
        cout << "This human can sleep \n";
    }
};

int main()
{
    Human human1;
    human1.name = "John";
    human1.age = 23;
    human1.occupation = "Developer";

    human1.eat();
    human1.sleep();

    return 0;
}