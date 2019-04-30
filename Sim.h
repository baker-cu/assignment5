#ifndef SIM_H
#define SIM_H

#include <iostream>
#include "BST.h"
#include "Student.cpp"
#include "Faculty.cpp"

using namespace std;

class Sim
{
    public:
        Sim();
        ~Sim();

        //print all students and their info in ascending id
        void printStu();
        //print all faculty and their info in ascending id
        void printFac();

        //find and display student info given ID
        void dispStu();
        //find and display faculty info given ID
        void dispFac();

        //given student's id print name and info of faculty
        void stuInfo();
        //given faculty's id print all student advisees info
        void facInfo();

        //add a new student
        //delete student given ID

        //add a new Faculty
        //delete faculty given ID

        //change a students advisor given ID's
        //remove an advisee from a faculty given ID's

        //rollback??????

        //exit

    private:


};

#endif
