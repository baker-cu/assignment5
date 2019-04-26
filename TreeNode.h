#include <iostream>
using namespace std;


//need to templatetize TreeNode to hold a value of type T
template <typename T>
class TreeNode
{
    public:
        TreeNode();
        TreeNode(int key);
        virtual ~TreeNode(); //why is it virtual...bc recursion?

        int key;
        T data; //will hold a student or faculty
        TreeNode *left;
        TreeNode *right;
};

/////implementation//////
template <typename T>
TreeNode<T>::TreeNode()
{
    left = NULL;
    right = NULL;
    data = NULL;
}

template <typename T>
TreeNode<T>::TreeNode(int k)
{
    left = NULL;
    right = NULL;
    key = k;
    data = NULL;
}

template <typename T>
TreeNode<T>::~TreeNode()
{
    //figure it out
}
