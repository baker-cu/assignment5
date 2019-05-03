#include <iostream>
#include "Sim.h"

inline Sim::Sim()
{
    masterStudent = StuBST();
    masterFaculty = FacBST();
    rollbackfac = GenStack<FacBST>();
    rollbackstu = GenStack<StuBST>();
    undoCount = 0;
    undoLimit = -5;

    //code to check if facultyTable and studentTable are in the directory
        //code to read the files to masterStudent and masterFaculty if found
    FILE *fp = fopen("studentTable.txt", "r");
    if(fp == NULL)
    {
        cout<<"Did not find studentTable.txt"<<endl;
    }
    else
    {
        masterStudent.deSerialize(masterStudent.root,fp);
        fclose(fp);
    }

    fp = fopen("facultyTable.txt", "r");
    if(fp == NULL)
    {
        cout<<"Did not find facultyTable.txt"<<endl;
    }
    else
    {
        masterFaculty.deSerialize(masterFaculty.root,fp);
        fclose(fp);
    }

}

/*inline Sim::~Sim()
{

}*/


//---------------------------------------1----------------------------------------
inline void Sim::printStu()
{
    if(masterStudent.isEmpty() == true)
        cout<<"There are no students in the database"<<endl;
    else
        masterStudent.printAll();
}

//--------------------------------------2-----------------------------------------
inline void Sim::printFac()
{
    if(masterFaculty.isEmpty() == true)
        cout<<"There is no faculty in the database"<<endl;
    else
        masterFaculty.printAll();
}

//-------------------------------------3-------------------------------------------
inline void Sim::dispStu(int id)
{
    if(masterStudent.contains(id))
    {
        Student stu = masterStudent.get(id);
        cout<<"Student name: "<<stu.getName()<<endl;
        cout<<"Major: "<<stu.getSubject()<<endl;
        cout<<"Level: "<<stu.getLevel()<<endl;
        cout<<"GPA: "<<stu.getGPA()<<endl;
        cout<<"Advisor ID#: "<<stu.getAdvisor()<<endl;
    }
    else
        cout<<"The student ID you have entered does not exist"<<endl;
}


//----------------------------------------4----------------------------------------
inline void Sim::dispFac(int id)
{
    cout<<"Checking for ID#: "<<id<<endl;
    if(masterFaculty.contains(id))
    {
        Faculty fac = masterFaculty.get(id);
        cout<<"Faculty name: "<<fac.getName()<<endl;
        cout<<"Subject: "<<fac.getSubject()<<endl;
        cout<<"Level: "<<fac.getLevel()<<endl;
    }
    else
        cout<<"The faculty ID you have entered does not exist"<<endl;
}

//----------------------------------------5-----------------------------------------
inline void Sim::stuFacInfo(int id)
{
    if(masterStudent.contains(id))
    {
        Student stu = masterStudent.get(id);
        int facultyID = stu.getAdvisor();
        dispFac(facultyID);
    }
    else
        cout<<"The student ID you have entered does not exists"<<endl;
}

//---------------------HELP----------------------6--------------------------------------
inline void Sim::facStuInfo(int id)
{
    if(masterFaculty.contains(id))
    {
        Faculty fac = masterFaculty.get(id);
        int *ads = fac.getAdvisees();
        int size = fac.getNumAdv();

        for(int x = -1; x<size; x++)
        {
            int stuID = ads[x];
            if(stuID == 0)
                break;
            dispStu(stuID);
            cout<<endl;
        }
    }
    else
        cout<<"The faculty ID you have entered does not exist"<<endl;
}

//-----------------------------------------7----------------------------------------------

inline void Sim::addStu(int i, string n, string l, string s, double g, int a)
{
    if(masterStudent.contains(i)==true)
        cout<<"The student ID you have entered already exists"<<endl;
    else if(masterFaculty.contains(i)==true)
    {
        undoCount++;
        StuBST sorigin(masterStudent);
        FacBST forigin(masterFaculty);
        rollbackstu.push(sorigin);//pushes old instance of masterStudent to the undo stack
        rollbackfac.push(forigin);

        Student newStu(i,n,l,s,g,a);
        masterStudent.insert(newStu);

        //add new student to its respective faculty advisee list
        Faculty tempFac = masterFaculty.get(a);
        tempFac.addAdvisee(i);
    }
    else
        cout<<"The faculty ID you have entered does not exitst"<<endl;
}

//-------------------------------------------8------------------------------------------
inline void Sim::deleteStu(int id)
{
    undoCount++;
    StuBST sorigin(masterStudent);
    FacBST forigin(masterFaculty);
    rollbackstu.push(sorigin);//pushes old instance of masterStudent to the undo stack
    rollbackfac.push(forigin);

    int adID = masterStudent.get(id).getAdvisor();
    masterFaculty.get(adID).removeAdvisee(id);//removes student from advisors advisee list
    masterStudent.deleteR(id);

}


//---------------------------------------------9--------------------------------------------
inline void Sim::addFac(int i, string n, string s, string l)
{
    if(masterFaculty.contains(i))
        cout<<"The faculty ID you have entered already exists"<<endl;
    else
    {
        undoCount++;
        StuBST sorigin(masterStudent);
        FacBST forigin(masterFaculty);
        rollbackstu.push(sorigin);//pushes old instance of masterStudent to the undo stack
        rollbackfac.push(forigin);

        Faculty newFac(i,n,s,l);
        masterFaculty.insert(newFac);
    }
}

//-----------------------------------------------10--------------------------------------
inline void Sim::deleteFac(int id)
{
    if(masterFaculty.contains(id) == false)
        cout<<"The database does not have that faculty ID"<<endl;
    else
    {
        undoCount++;
        StuBST sorigin(masterStudent);
        FacBST forigin(masterFaculty);
        rollbackstu.push(sorigin);//pushes old instance of masterStudent to the undo stack
        rollbackfac.push(forigin);

        //give students a new advisor
        Faculty fac = masterFaculty.get(id);
        int *ads = fac.getAdvisees();
        int size = fac.getSizeAdv();

        masterFaculty.deleteR(id);

        for(int x = 0; x<size; x++)
        {
            if(masterFaculty.isEmpty() == true)
                cout<<"Faculty tree is empty."<<endl;
            Faculty newFac = masterFaculty.root->data;
            newFac.addAdvisee(ads[x]);
        }
    }
}

//------------------------------------------------------11---------------------------------
inline void Sim::changeAdvisor(int stuID, int facID)
{
    if(masterFaculty.contains(facID)==true && masterStudent.contains(stuID)==true)
    {
        undoCount++;
        StuBST sorigin(masterStudent);
        FacBST forigin(masterFaculty);
        rollbackstu.push(sorigin);//pushes old instance of masterStudent to the undo stack
        rollbackfac.push(forigin);

        Student stu = masterStudent.get(stuID);
        Faculty oldFac = masterFaculty.get(stu.getAdvisor());
        Faculty newFac = masterFaculty.get(facID);

        //change the students advisor
        stu.setAdvisor(facID);

        //add student to new advisor advisee list
        newFac.addAdvisee(stuID);

        //delete student from old advisor advisee list
        oldFac.removeAdvisee(stuID);
    }
    else if(masterFaculty.contains(facID)==false)
    {
        cout<<"The faculty ID you have entered does not exists"<<endl;
    }
    else
        cout<<"The student ID you have enterd does not exists"<<endl;
}

//-----------------------------------------------------12------------------------------------
inline void Sim::removeAd(int facID, int stuID)
{
    if(masterFaculty.contains(facID)==true && masterStudent.contains(stuID)==true)
    {
        undoCount++;
        StuBST sorigin(masterStudent);
        FacBST forigin(masterFaculty);
        rollbackstu.push(sorigin);//pushes old instance of masterStudent to the undo stack
        rollbackfac.push(forigin);

        Student stu = masterStudent.get(stuID);
        Faculty fac = masterFaculty.get(facID);

        fac.removeAdvisee(stuID);
        //give stu a new random advisor?
    }
    else if(masterFaculty.contains(facID)==false)
    {
        cout<<"The faculaty ID you ented does not exist"<<endl;;
    }
    else
        cout<<"The student ID you ented does not exist"<<endl;
}

//-----------------------------------------13-------------------------------------------

inline void Sim::undo()
{
    if(undoCount == undoLimit)
    {
        cout<<"Undo is not availible."<<endl;
        return;
    }
    else if(undoCount > undoLimit)
    {
        masterStudent = rollbackstu.pop();
        masterFaculty = rollbackfac.pop();
        undoLimit++;
    }
}

//-----------------------------------------------14----------------------------------------
inline void Sim::exit()
{
    FILE *fp = fopen("studentTable.txt", "w");
    if(fp == NULL)
        throw string("Could not open studentTable.txt");
    masterStudent.serialize(masterStudent.root,fp);
    fclose(fp);

    fp = fopen("facultyTable.txt","w");
    if(fp == NULL)
        throw string("Could not open facultyTable.txt");
    masterFaculty.serialize(masterFaculty.root,fp);
    fclose(fp);
}
