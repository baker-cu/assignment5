include <iostream>
using namespace std;

class TreeNode
{
    public:
        TreeNode();
        TreeNode(int key);
        virtual ~TreeNode(); //why is it virtual...bc recursion?
    private:
        int key;
        TreeNode *left;
        TreeNode *right;
};

/////implementation//////
TreeNode::TreeNode()
{
    left = NULL;
    right = NULL;
}

TreeNode::TreeNode(int k)
{
    left = NULL;
    right = NULL;
    key = k;
}

virtual TreeNode::~TreeNode()
{
    //figure it out
}
