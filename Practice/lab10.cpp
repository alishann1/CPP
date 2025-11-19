#include <iostream>
using namespace std;

template <class Object>

class TreeNode
{
private:
    Object *data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(Object *x)
    {
        this->data = x;
        this->left = this->right = nullptr;
    };

    Object *getData() { return this->data; };
    void setData(Object *x) { this->data = x; };
    TreeNode *getLeft() { return left; };
    void setLeft(TreeNode *left) { this->left = left; };
    TreeNode *getRight() { return right; };
    void setRight(TreeNode *right) { this->right = right; };

    int isLeaf()
    {
        if (this->left == nullptr && this->right == nullptr)
            return 1;
        return 0;
    };
};
