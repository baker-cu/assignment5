#include <iostream>
#include "StuBST.h"

using namespace std;

void StuBST::insert(Student p)
{
    int value = p.getID();
    //check if the tree is empty
    //check if value exists, if not continue
    if(contains(value))
    {
        cout<<"Tree already contains this key"<<endl;
        return;
    }
    TempTreeNode<T> *node = new TempTreeNode<T>(value);//node to be inserted
    node->data = p;

    if(isEmpty())//empty tree
    {
        root = node;
    }
    else//not an empty tree...continue to add
    {
        TempTreeNode<T> *current = root;
        TempTreeNode<T> *parent; //empty TempTreeNode

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
