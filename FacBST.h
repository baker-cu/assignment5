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
