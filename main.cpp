#include <iostream>
#include "BST.h"
#include "Person.h"
#include "Student.cpp"

using namespace std;

int main()
{
    Student s1 = Student(45634,"bob","frosh","math",4.0,9863);
    Student s2 = Student(98464,"carl","frosh","math",3.9,8694);
    Student s3 = Student(1686,"syd","frosh","math",4.2,9896);

    BST<Student> sb = BST<Student>();

    sb.insert(s1);
    sb.insert(s2);
    sb.deleteR(45634);
    sb.insert(s3);

    sb.printTree();

    cout<<sb.get(98464).getGPA()<<endl;

    return 0;
}
