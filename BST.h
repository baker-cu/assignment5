#include <iostream>
#include "TreeNode.h"
using namespace std;

class BST
{
    public:
        BST();
        virtual ~BST();
        void insert(int value);
        bool contains(int value); //aka search
        bool deleteR(int k);
        TreeNode* getSuccessor(TreeNode* d);

        TreeNode* getMin();
        TreeNode* getMax();
        bool isEmpty();
        void printTree();
        void recPrint(TreeNode *node);

    private:
        TreeNode *root;

};

BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    //iterate and delete
    //figure out
}

void BST::printTree()
{
    recPrint(root);
}

void BST::recPrint(TreeNode *node)
{
    if(node == NULL)
        return;

    recPrint(node->left);
    cout<< node->key << endl;
    recPrint(node->right);
}

void BST::insert(int value)
{
    //check if the tree is empty
    //check if value exists, if not continue
    if(contains(value))
    {
        cout<<"Tree already contains this key"<<endl;
        return;
    }
    TreeNode *node = new TreeNode(value);

    if(isEmpty())//empty tree
    {
        root = node;
    }
    else//not an empty tree...continue to add
    {
        TreeNode *current = root;
        TreeNode *parent; //empty TreeNode

        while(true)//lets look for our inserstion point
        {
            parent = current;
            if(value < current->key)//go left
            {
                current = current->left;
                if(current == NULL)//found the our location
                {
                    parent->left = node;
                    break;
                }
            }
            else//go right
            {
                current = current->right;
                if(current == NULL)//found our new node a home
                {
                    parent->right = node;
                    break;
                }
            }
        }
    }
}

bool BST::isEmpty()
{
    return(root == NULL);
}

bool BST::contains(int value)
{
    if(isEmpty())//empty tree nothing exists
        return false;

    TreeNode *current = root;
    while(current->key != value)
    {
        if(value < current->key)
            current = current->left;
        else
            current = current->right;

        if(current == NULL) //item not in tree
            return false;
    }
    return true;
}

bool BST::deleteR(int k)
{
    if(isEmpty())
        return false;

    //check if key/value exits in tree
    if(!contains(k))
        return false;

    TreeNode *current = root;
    TreeNode *parent = root;
    bool isLeft = true;

    //now lets iterate and update our pointers
    while(current->key != k)
    {
        parent = current;

        if(k < current->key)
        {
            isLeft = true;
            current = current->left;
        }
        else
        {
            isLeft = false;
            current = current->right;
        }
        if(current == NULL)
            return false;
    }
    //all pointers are set and node can be deleted

    if(current->left == NULL && current->right == NULL)//leaf node no children
    {
        if(current == root)
            root = NULL;

        else if (isLeft)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
    }

    //we need to check if node to be deleted has one child on left
    else if(current->right == NULL)
    {
        if(current = root)
            root = current->left;
        else if (isLeft)
        {
            parent->left = current->left;
        }
        else
        {
            parent->right = current->left;
        }
    }

    //check if node to be deleted
    else if (current->left == NULL)
    {
        if(current = root)
            root = current->right;
        else if (isLeft)
        {
            parent->right = current->right;
        }
        else
        {
            parent->right = current->right;
        }
    }

    else //the node to be delted has two children
    {
        //find the successor of the node to be deleted
        TreeNode *successor = getSuccessor(current);

        if(current = root)
            root = successor;
        else if (isLeft)
            parent->left = successor;
        else
            parent->right = successor;

        successor->left = current->left;
    }
    delete current;

    return true;


}

TreeNode* BST::getSuccessor(TreeNode *d)
{
    TreeNode *sp = d; //sucessor's parent
    TreeNode *successor = d;
    TreeNode *current = d->right;

    while(current != NULL)
    {
        sp = successor;
        successor = current;
        current = current->left;
    }

    //we need to check if successor is a descendant of right child
    if(successor != d->right)
    {
        sp->left = successor->right;
        successor->right = d->right;
    }
    return successor;
}

TreeNode* BST::getMin()
{
    TreeNode *node = root;
    TreeNode *prev = NULL;

    if(isEmpty())
    {
        cout<<"The BST is empty"<<endl;
        return prev;
    }

    while(node != NULL)
    {
        prev = node;
        node = node->left;
    }
    return prev;
}

TreeNode* BST::getMax()
{
    TreeNode *node = root;
    TreeNode *prev = NULL;

    if(isEmpty())
    {
        cout<<"The BST is empty"<<endl;
        return(prev);
    }

    while(node != NULL)
    {
        prev = node;
        node = node->left;
    }
    return prev;
}
