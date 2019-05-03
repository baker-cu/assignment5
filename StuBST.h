#include <iostream>
#include "BST.h"
#include "Student.cpp"

using namespace std;

class StuBST: public BST<Student>
{
    public:
        void printAll();
        void recPrintAll(TempTreeNode<Student> *node);

        Student get(int value);

        void serialize(TempTreeNode<Student>* r, FILE *fp);
        void deSerialize(TempTreeNode<Student>*& r, FILE *fp);
};

inline void StuBST::printAll()
{
    recPrintAll(root);
}

inline void StuBST::recPrintAll(TempTreeNode<Student> *node)
{
    int id;
    if(node == NULL)
        return;

    recPrintAll(node->left);
    Student stu = node->data;
    cout<<"ID#: "<<stu.getID()<<endl;
    cout<<"Student name: "<<stu.getName()<<endl;
    cout<<"Major: "<<stu.getSubject()<<endl;
    cout<<"Level: "<<stu.getLevel()<<endl;
    cout<<"GPA: "<<stu.getGPA()<<endl;
    cout<<"Advisor ID#: "<<stu.getAdvisor()<<endl;
    cout<<endl;
    recPrintAll(node->right);
}

inline void StuBST::serialize(TempTreeNode<Student>* r, FILE *fp)
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

inline void StuBST::deSerialize(TempTreeNode<Student>*& r, FILE *fp)
{
    int val;
    if(!fscanf(fp, "%d ", &val) || val == MARKER)
        return;

    root = new TempTreeNode<Student>(val);
    deSerialize(r->left, fp);
    deSerialize(r->right, fp);
}

inline Student StuBST::get(int value)
{
    if(isEmpty()==true)//empty tree nothing exists
        cout<<"BST is empty"<<endl;

    TempTreeNode<Student> *current = root;
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
