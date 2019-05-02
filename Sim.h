#ifndef SIM_H
#define SIM_H

#include <iostream>
#include "StuBST.h"
#include "FacBST.h"
#include "GenStack.h"

using namespace std;

class Sim
{
    public:
        Sim();
        //~Sim();

        //print all students and their info in ascending id
        void printStu();
        //print all faculty and their info in ascending id
        void printFac();

        //find and display student info given ID
        void dispStu(int id);
        //find and display faculty info given ID
        void dispFac(int id);

        //given student's id print name and info of faculty
        void stuFacInfo(int id);
        //given faculty's id print all student advisees info
        void facStuInfo(int id);

        //add a new student
        void addStu(int i, string n, string l, string s, double g, int a);
        //delete student given ID
        void deleteStu(int id);

        //add a new Faculty
        void addFac(int i, string n, string s, string l);
        //delete faculty given ID
        void deleteFac(int id);

        //change a students advisor given ID's
        void changeAdvisor(int stuID, int facID);
        //remove an advisee from a faculty given ID's
        void removeAd(int facID, int stuID);

        //rollback, up to 5 times
        void undo();

        //exit
        void exit();

    private:
        StuBST masterStudent;
        FacBST masterFaculty;
        GenStack<FacBST> rollbackfac;
        GenStack<StuBST> rollbackstu;
        int undoCount;
        int undoLimit;

};

#endif
