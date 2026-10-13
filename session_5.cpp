#include <iostream>
using namespace std;

struct Subject
{
    char Name[10] ;
    short Score_Subject = 0;
    short Score_Student = 0;
};

struct Student
{
    short ID;
    char First_name[20];
    char Last_name[20];
    short year_of_study;
    Subject Subject[2];
};


void ShowStudentS(const Student student[], int NumberOfstudents) 
{
    cout << "all Student : \n";


    for (int i = 0; i < NumberOfstudents;i++)
    {
    
        cout << "student number : " << i + 1 << "\n";

        cout << "name is   : " << student[i].First_name << "  " << student[i].Last_name << endl;
        cout << "year_of_study is   : " << student[i].year_of_study << "\n";
        cout << "student ID : " << student[i].ID << "\n";

        for (int j = 0; j < 2; j++)
        {
            cout << "Subject  :  "  << student[i].Subject[j].Name << "\n";
            cout << "Score_Subject :  " << student[i].Subject[j].Score_Subject << "\n";
            cout << "Score_Student :  " << student[i].Subject[j].Score_Student << "\n";

        }
        cout << "--------------------------------------------\n";
    }
}

void CalculationTotalDegree(const Student student[],short id, int NumberOfstudents)
{
    int resultdegreeStudent = 0;
    int resultdegreeSubject = 0;

    for (int i = 0; i < NumberOfstudents; i++)
    {

        if (id == student[i].ID)
        {
            for (int j = 0; j < 2;j++)
            {
                resultdegreeStudent += student[i].Subject[j].Score_Student;
                resultdegreeSubject += student[i].Subject[j].Score_Subject;

            }             

            cout << "the total score of student = " << resultdegreeStudent << " out of  " << resultdegreeSubject << "\n";
            return ;
        }
    }
}


int main()
{
    int NumberOfstudents;
    int id = 0;
    cout << "inter number if students : ";
    cin >> NumberOfstudents;
    cout << "\n";
    Student* student = new Student[NumberOfstudents];

    for (int i = 0; i < NumberOfstudents; i++)
    {
        cout << "student number : " << i + 1 <<  "\n";

        cout << "inter fname : " ;
        cin >> student[i].First_name;

        cout << "inter lname : ";
        cin >> student[i].Last_name;

        cout << "inter yearofstudy : ";
        cin >> student[i].year_of_study;

        cout << "inter ID : ";
        cin >> student[i].ID;
        
        for (int j = 0; j< 2;j++)
        { 
            cout << "inter 1  Subject : ";

            cout << " Name : ";
            cin >> student[i].Subject[j].Name;

            cout << " Score_Subject : ";
            cin >> student[i].Subject[j].Score_Subject;

            cout << " Score_Student : ";
            cin >> student[i].Subject[j].Score_Student;

            cout << "\n";

        }
    }   
    cout << "\n";

    ShowStudentS(student, NumberOfstudents);

    cout << "inetr id of the student that you need calc his total degree :";
    cin >> id;
    CalculationTotalDegree(student,id, NumberOfstudents);
    delete[]student;
}

