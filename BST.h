#ifndef BST_H
#define BST_H

#include <iostream>
#include <stdio.h>
#include "TempTreeNode.h"
using namespace std;

template <typename T>
class BST
{
    public:
        BST();
        BST(const BST<T> &original);
        //virtual ~BST();
        //void recDelete(TempTreeNode<T>* d);
        void insert(T p);
        bool contains(int value); //aka search
        bool deleteR(int k);
        T get(int value);
        TempTreeNode<T>* getSuccessor(TempTreeNode<T>* d);

        TempTreeNode<T>* getMin();
        TempTreeNode<T>* getMax();
        bool isEmpty();
        void printTree();
        void recPrint(TempTreeNode<T> *node);
        TempTreeNode<T>* treeCopy(const TempTreeNode<T>* original);

        void serialize(TempTreeNode<T>* r, FILE *fP);
        void deSerialize(TempTreeNode<T>*& r, FILE *fP);

        TempTreeNode<T> *root;
};

#define MARKER -1

template <typename T>
BST<T>::BST()
{
    root = NULL;
}

/*template <typename T>
BST<T>::~BST()
{
    recDelete(root);
}

template <typename T>
void BST<T>::recDelete(TempTreeNode<T>* d)
{
    if(d)
    {
        recDelete(d->left);
        recDelete(d->right);
        delete d;
    }
}*/

template <typename T>
BST<T>::BST(const BST<T> &original)
{
    root = treeCopy(original.root);
}

template <typename T>
TempTreeNode<T>* BST<T>::treeCopy(const TempTreeNode<T>* original)
{
    if(original == NULL)
        return NULL;
    else
    {
        TempTreeNode<T> *copyNode = new TempTreeNode<T>();
        copyNode->key = original->key;
        copyNode->data = original->data;
        copyNode->left = treeCopy(original->left);
        copyNode->right = treeCopy(original->right);
        return copyNode;
    }
}

template <typename T>
void BST<T>::printTree()
{
    recPrint(root);
}

template <typename T>
void BST<T>::recPrint(TempTreeNode<T> *node)
{
    if(node == NULL)
        return;

    recPrint(node->left);
    cout<< node->key << endl;
    recPrint(node->right);
}

template <typename T>
void BST<T>::insert(T p)
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

template <typename T>
bool BST<T>::isEmpty()
{
    return(root == NULL);
}

template <typename T>
bool BST<T>::contains(int value)
{
    if(isEmpty())//empty tree nothing exists
        return false;

    TempTreeNode<T> *current = root;
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

template <typename T>
inline bool BST<T>::deleteR(int k)
{
    if(isEmpty())
        return false;

    //check if key/value exits in tree
    if(!contains(k))
        return false;

    TempTreeNode<T> *current = root;
    TempTreeNode<T> *parent = root;
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
        TempTreeNode<T> *successor = getSuccessor(current);

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

template <typename T>
inline TempTreeNode<T>* BST<T>::getSuccessor(TempTreeNode<T> *d)
{
    TempTreeNode<T> *sp = d; //sucessor's parent
    TempTreeNode<T> *successor = d;
    TempTreeNode<T> *current = d->right;

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

template <typename T>
inline TempTreeNode<T>* BST<T>::getMin()
{
    TempTreeNode<T> *node = root;
    TempTreeNode<T> *prev = NULL;

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

template <typename T>
inline TempTreeNode<T>* BST<T>::getMax()
{
    TempTreeNode<T> *node = root;
    TempTreeNode<T> *prev = NULL;

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

template <typename T>
inline T BST<T>::get(int value)
{
    if(isEmpty()==true)//empty tree nothing exists
        cout<<"BST is empty"<<endl;

    TempTreeNode<T> *current = root;
    while(current->key != value)
    {
        if(value < current->key)
            current = current->left;
        else
            current = current->right;

        if(current == NULL) //item not in tree
            cout<<"ID was not found"<<endl;
    }
    return (current->data);
}

template <typename T>
inline void BST<T>::serialize(TempTreeNode<T>* r, FILE *fp)
{
    if(r == NULL)
    {
        fprintf(fp, "%d ", MARKER);
        return;
    }

    fprintf(fp, "%d ", r->key);
    serialize(r->left, fp);
    serialize(r->right, fp);
}

template <typename T>
inline void BST<T>::deSerialize(TempTreeNode<T>*& r, FILE *fp)
{
    int val;
    if(!fscanf(fp, "%d ", &val) || val == MARKER)
        return;

    root = new TempTreeNode<T>(val);
    deSerialize(r->left, fp);
    deSerialize(r->right, fp);
}

#endif
