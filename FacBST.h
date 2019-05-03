#include <iostream>
#include "BST.h"
#include "Faculty.cpp"

using namespace std;

class FacBST: public BST<Faculty>
{
    public:
        FacBST();
        //~FacBST();
        void printAll();
        void recPrintAll(TempTreeNode<Faculty> *node);

        void serialize(TempTreeNode<Faculty>* r, FILE *fp);
        void deSerialize(TempTreeNode<Faculty>*& r, FILE *fp);

        Faculty get(int value);
};

inline FacBST::FacBST():BST()
{

}

/*FacBST::~FacBST()
{

}*/

inline void FacBST::printAll()
{
    recPrintAll(root);
}

inline void FacBST::recPrintAll(TempTreeNode<Faculty> *node)
{
    int id;
    if(node == NULL)
        return;

    recPrintAll(node->left);
    Faculty fac = node->data;
    cout<<"ID#: "<<fac.getID()<<endl;
    cout<<"Faculty name: "<<fac.getName()<<endl;
    cout<<"Subject: "<<fac.getSubject()<<endl;
    cout<<"Level: "<<fac.getLevel()<<endl;
    cout<<endl;
    recPrintAll(node->right);
}

inline void FacBST::serialize(TempTreeNode<Faculty>* r, FILE *fp)
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

inline void FacBST::deSerialize(TempTreeNode<Faculty>*& r, FILE *fp)
{
    int val;
    if(!fscanf(fp, "%d ", &val) || val == MARKER)
        return;

    root = new TempTreeNode<Faculty>(val);
    deSerialize(r->left, fp);
    deSerialize(r->right, fp);
}

inline Faculty FacBST::get(int value)
{
    if(isEmpty()==true)//empty tree nothing exists
        cout<<"BST is empty"<<endl;

    TempTreeNode<Faculty> *current = root;
    while(current->key != value)
    {
        if(value < current->key)
            current = current->left;
        else
            current = current->right;

        if(current == NULL) //item not in tree
            cout<<"ID was not found"<<endl;
            break;
    }
    return (current->data);
}
