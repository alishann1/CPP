#include <iostream>
#include <stack>
#include <string>

using namespace std;

class TextEditor
{
private:
    string content;
    stack<string> history;

public:
    TextEditor()
    {
        content = "";
    }

    void insertText(string text)
    {
        content += text;
        history.push(text);

        cout << "Action: Inserted \"" << text << "\"" << endl;
        cout << ">> Output: String \"" << text << "\" pushed to stack." << endl;
        displayContent();
    }

    void undo()
    {
        if (history.empty())
        {
            cout << "Action: Undo" << endl;
            cout << ">> Error: Nothing to undo! Stack is empty." << endl;
            return;
        }

        string lastAdded = history.top();
        history.pop();

        content.resize(content.length() - lastAdded.length());

        cout << "Action: Undo" << endl;
        cout << ">> Output: String \"" << lastAdded << "\" popped from stack." << endl;
        displayContent();
    }

    void displayContent()
    {
        cout << "   [Current Text Editor Content]: " << content << "\n"
             << endl;
    }
};

int main()
{
    TextEditor editor;

    cout << "--- TEXT EDITOR STARTED ---\n"
         << endl;

    editor.insertText("Hello");
    editor.insertText("World");

    editor.undo();

    editor.undo();

    editor.undo();

    return 0;
}