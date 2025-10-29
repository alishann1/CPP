#include <iostream>
#include <string>
#include <stack>

using namespace std;

int evaluatePostfix(string postfix)
{
    stack<int> s;

    for (char c : postfix)
    {
        if (isdigit(c))
        {
            s.push(c - '0');
        }
        else
        {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();

            switch (c)
            {
            case '+':
                s.push(operand1 + operand2);
                break;
            case '-':
                s.push(operand1 - operand2);
                break;
            case '*':
                s.push(operand1 * operand2);
                break;
            case '/':
                s.push(operand1 / operand2);
                break;
            }
        }
    }
    return s.top();
}

int main()
{
    string postfixExpression = "231*+9-";

    cout << "Postfix Expression: " << postfixExpression << endl;
    cout << "Result: " << evaluatePostfix(postfixExpression) << endl;

    postfixExpression = "123*+";
    cout << "Postfix Expression: " << postfixExpression << endl;
    cout << "Result: " << evaluatePostfix(postfixExpression) << endl;

    return 0;
}
