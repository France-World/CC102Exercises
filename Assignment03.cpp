/*
Note: I used pointers because after doing to inputs and assignments of value i realised that
the datas inside the vector is not being saved.
*/
#include <iostream>
#include <vector>
using namespace std;

struct StudentsList{
    int StudentId;
    string StudentName;
    string StudentCourse;
    int StudentGpa;
    string StudentAcadStanding;

};

void InputAndDuplicateChecker(vector<StudentsList> &Students, int  Nstudents){
        bool dupFound;
        bool notRange;


        for (int i = 0; i < Nstudents; i++) {
        bool dupFound;
            do {
                dupFound = false;
                cout << "Enter Student " << i + 1 << " Id Numbers Only: ";
                cin >> Students[i].StudentId;
                for (int j = 0; j < i; j++) {
                    if (Students[i].StudentId == Students[j].StudentId) {
                        dupFound = true;
                        cout << "User Id already exists! Try again"<<'\n';
                        break;
                    }
                }
            }
            while (dupFound == true);

                 cin.ignore();
                cout<<"Enter Student"<<i+1<<" Name: ";
                getline(cin,Students[i].StudentName);
                cout<<"Enter Student"<<i+1<<" Course: ";
                cin>>Students[i].StudentCourse;

                do{
                    notRange=false;
                cout<<"Enter Student"<<i+1<<" Gpa 0-100: ";
                cin>>Students[i].StudentGpa;
                if(Students[i].StudentGpa>100||Students[i].StudentGpa<0){
                    notRange=true;
                    cout<<"Hala ka sinabi nang 0-100"<<endl;
                }
                }

                while(notRange == true);

                 cin.ignore();


                }
            }
    void PrintTable (vector<StudentsList>Students, int  Nstudents){
            for(int i=0; i<Nstudents; i++){
                cout<<"=========";
            }
            cout<<" STUDENT RECORD";
            for(int i=0; i<Nstudents; i++){
                cout<<"=========";
            }
            cout<<endl;
            cout<<"\t\t\t\t";


            for(int i= 0; i<Nstudents;i++){
                    cout<<"Student"<<i+1<<"\t";

            }
            cout<< endl;
            cout<<"Student Id\t\t\t";
            for(int i=0;i<Nstudents; i++){
                    cout<<Students[i].StudentId<<"\t\t";

            }
            cout<<endl;
            cout<<"Student Name\t\t\t";
            for(int i=0;i<Nstudents; i++){
                    cout<<Students[i].StudentName<<"\t\t";

            }
            cout<<endl;
            cout<<"Student Course\t\t\t";
            for(int i=0;i<Nstudents; i++){
                    cout<<Students[i].StudentCourse<<"\t\t";

            }
            cout<<endl;
            cout<<"Student Gpa\t\t\t";
            for(int i=0;i<Nstudents; i++){
                    cout<<Students[i].StudentGpa<<"\t\t";

            }
            cout<<endl;
            cout<<"Student Academic Standing\t";
            for(int i=0;i<Nstudents; i++){
                    cout<<Students[i].StudentAcadStanding<<"\t";

            }
            cout<<endl;





    }
void CheckRemarks(vector<StudentsList>&Students, int  Nstudents){
    for(int i=0; i<Nstudents;i++){
        if(Students[i].StudentGpa>=90){
            Students[i].StudentAcadStanding="Excellent";
        }
        else if(Students[i].StudentGpa>=80){
            Students[i].StudentAcadStanding="Very Good";

        }
        else if(Students[i].StudentGpa>=70){
            Students[i].StudentAcadStanding="Good";

        }
        else if(Students[i].StudentGpa>=60){
            Students[i].StudentAcadStanding="Passing";

        }
        else if(Students[i].StudentGpa<60){
            Students[i].StudentAcadStanding="Failed";

        }

    }


}


        int main(){
            char choice;
            do{
            int n;

                cout<<"How many Student to store: ";
                cin>>n;

            vector<StudentsList> Students(n);

            InputAndDuplicateChecker(Students,n);
            CheckRemarks(Students,n);
            PrintTable(Students,n);
            cout<<"TRY AGAIN?/Y";
            cin>>choice;

            }
             while(toupper(choice)=='Y');







return 0;
        }

