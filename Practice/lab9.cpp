#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;

    TreeNode(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

int main()
{
    TreeNode *firstNode = new TreeNode(2);
    TreeNode *secondNode = new TreeNode(3);
    TreeNode *thirdNode = new TreeNode(4);
    TreeNode *fourthNode = new TreeNode(5);

    firstNode->left = secondNode;
    firstNode->right = thirdNode;
    secondNode->left = fourthNode;
    return 0;
}