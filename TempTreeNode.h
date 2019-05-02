#include <iostream>
using namespace std;


//need to templatetize TempTreeNode to hold a value of type T
template <typename T>
class TempTreeNode
{
    public:
        TempTreeNode();
        TempTreeNode(int key);
        //virtual ~TempTreeNode(); //why is it virtual...bc recursion?

        int key;
        T data; //will hold a student or faculty
        TempTreeNode *left;
        TempTreeNode *right;
};

/////implementation//////
template <typename T>
inline TempTreeNode<T>::TempTreeNode()
{
    left = NULL;
    right = NULL;
}

template <typename T>
inline TempTreeNode<T>::TempTreeNode(int k)
{
    left = NULL;
    right = NULL;
    key = k;
}

/*template <typename T>
inline TempTreeNode<T>::~TempTreeNode()
{
    //figure it out
}*/
