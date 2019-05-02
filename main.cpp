#include <iostream>
#include "Sim.cpp"


using namespace std;

int main()
{
    while(true)
    {
        Sim simulation = Sim();
        int e = 0;

        int id;
        string n;
        string l;
        string s;
        double g;
        int a;
        int fid;

        int choice;
        cout<<"1. Print all students and their information (sorted by ascending id #)"<<endl;
        cout<<"2. Print all faculty and their information (sorted by ascending id #)"<<endl;
        cout<<"3. Find and display student information given the students id"<<endl;
        cout<<"4. Find and display faculty information given the faculty id"<<endl;
        cout<<"5. Given a student’s id, print the name and info of their faculty advisor"<<endl;
        cout<<"6. Given a faculty id, print ALL the names and info of his/her advisees."<<endl;
        cout<<"7. Add a new student"<<endl;
        cout<<"8. Delete a student given the id"<<endl;
        cout<<"9. Add a new faculty member"<<endl;
        cout<<"10. Delete a faculty member given the id."<<endl;
        cout<<"11. Change a student’s advisor given the student id and the new faculty id."<<endl;
        cout<<"12. Remove an advisee from a faculty member given the ids"<<endl;
        cout<<"13. Rollback"<<endl;
        cout<<"14. Exit"<<endl;

        cout<<"Enter the number of the action you would like to do: "<<endl;
        cin>>choice;

        switch (choice)
        {
            case 1:simulation.printStu();

            case 2:simulation.printFac();

            case 3:cout<<"Enter the ID# of the student: "<<endl;
                   cin>>id;
                   simulation.dispStu(id);
                   break;

            case 4:cout<<"Enter the ID# of the faculty: "<<endl;
                   cin>>id;
                   simulation.dispFac(id);
                   break;

            case 5:cout<<"Enter the ID# of the student: "<<endl;
                   cin>>id;
                   simulation.stuFacInfo(id);
                   break;

            case 6:cout<<"Enter the ID# of the faculty: "<<endl;
                   cin>>id;
                   simulation.facStuInfo(id);
                   break;

            case 7:cout<<"Enter the ID# of the new student: "<<endl;
                   cin>>id;
                   cout<<"Enter the name of the student: "<<endl;
                   cin>>n;
                   cout<<"Enter the level of the student: "<<endl;
                   cin>>l;
                   cout<<"Enter the subject the student is studying: "<<endl;
                   cin>>s;
                   cout<<"Enter the students GPA: "<<endl;
                   cin>>g;
                   cout<<"Enter the advisor ID#: "<<endl;
                   cin>>a;
                   simulation.addStu(id,n,l,s,g,a);
                   break;

            case 8:cout<<"Enter the ID# of the student: "<<endl;
                   cin>>id;
                   simulation.deleteStu(id);
                   break;

            case 9:cout<<"Enter the ID# of the faculty member: "<<endl;
                   cin>>id;
                   cout<<"Enter the name of the faculty: "<<endl;
                   cin>>n;
                   cout<<"Enter the subject they teach: "<<endl;
                   cin>>s;
                   cout<<"Enter the faculty member's level: "<<endl;
                   cin>>l;
                   simulation.addFac(id,n,s,l);
                   break;

            case 10:cout<<"Enter the ID# of the faculty you would like to delete: "<<endl;
                    cin>>id;
                    simulation.deleteFac(id);
                    break;

            case 11:cout<<"Enter the ID# of the student: "<<endl;
                    cin>>id;
                    cout<<"Enter the ID# of the faculty member: "<<endl;
                    cin>>fid;
                    simulation.changeAdvisor(id,fid);
                    break;

            case 12:cout<<"Enter the ID# of the faculty member: "<<endl;
                    cin>>fid;
                    cout<<"Enter the ID# of the student: "<<endl;
                    cin>>id;
                    simulation.removeAd(fid,id);
                    break;

            case 13:cout<<"You have chosen to undo."<<endl;
                    break;

            case 14:cout<<"You have chosen to exit"<<endl;
                    e = 1;
                    break;

        }
        if (e==1)
        break;
    }

    return 0;
}
