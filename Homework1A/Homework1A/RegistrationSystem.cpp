#include "RegistrationSystem.h"
#include <string>
using namespace std;
RegistrationSystem::RegistrationSystem()
{

    noOfStudents = 0;
    students = new Student[noOfStudents];

}

void RegistrationSystem::addStudent( const int studentId, const string firstName, const string lastName )
{
    for(unsigned int i = 0; i < noOfStudents; i++)
    {
        if(students[i].getStudentId() == studentId)
        {
            cout << "Student "<< studentId <<" already exists" << endl;
            return;
        }
    }

    Student student(firstName, lastName, studentId);
    if(noOfStudents == 0)
    {
        noOfStudents++;
        delete [] students;
        students = NULL;
        students = new Student[noOfStudents];
        students[noOfStudents - 1] = student;
        cout << "Student " << studentId << " has been added" << endl;
    }
    else
    {
        noOfStudents++;
        Student *tempStudents = new Student[noOfStudents];

        for(unsigned int i = 0; i < noOfStudents - 1 ; i++)
        {
            tempStudents[i] = students[i];
        }
        delete[] students;
        students = NULL;

        students = new Student[noOfStudents];

        for(unsigned int j = 0; j < noOfStudents; j++)
        {
            students[j] = tempStudents[j];
        }

        students[noOfStudents - 1] = student;
        cout << "Student " << studentId << " has been added"<<endl;
        //cout << students[noOfStudents - 1].getStudentFirstName()<<endl;
        sortStudentsArray();
        delete [] tempStudents;
        tempStudents = NULL;
    }
}
void RegistrationSystem::deleteStudent( const int studentId )
{
    if(noOfStudents >= 1)
    {
        for(unsigned int i = 0; i < noOfStudents; i++)
        {
            if(students[i].getStudentId() == studentId )
            {
                for(unsigned int k = i; k < noOfStudents - 1; k++)
                {
                    students[k] = students[k + 1];
                }
                noOfStudents--;
                cout << "Student " << studentId << " has been deleted" << endl;
                return;
            }
        }
        cout << "Student " << studentId << " does not exist." << endl;
    }
}






void RegistrationSystem::showStudent( const int studentId )
{
    for(unsigned int i = 0; i < noOfStudents; i++)
    {
        if(students[i].getStudentId() == studentId )
        {
            cout<< "Student id" << "\t"   <<"First name"    <<  "\t"<<"Last name"<<endl;
            cout << students[i].getStudentId()<< "\t\t"<<students[i].getStudentFirstName()<<"\t\t"<< students[i].getStudentLastName()<<endl;
            return;
        }
    }
    cout << "Student " << studentId <<" does not exist"<< endl;

}





void RegistrationSystem::showAllStudents()
{
    if(noOfStudents == 0)
    {
        cout << "There are no students in the system"<<endl;
    }
    else
        {
    cout << "Student id" << "\t" << "First name" << "\t" << "Last name" <<endl;

    for(unsigned int i = 0; i < noOfStudents; i++)
    {
        cout << students[i].getStudentId() << "\t\t" << students[i].getStudentFirstName() << "\t\t" << students[i].getStudentLastName()<<endl;
    }
    }
}


void RegistrationSystem::sortStudentsArray()
{
    int var;
    Student temp;
    for (unsigned int i = 0; i < noOfStudents - 1; i++)
    {
        var = i;
        for (unsigned int j = i + 1; j < noOfStudents; j++)
        {
            if (students[j].getStudentId() < students[var].getStudentId())
            {
                var = j;
            }
        }
        temp = students[i];
        students[i] = students[var];
        students[var] = temp;


    }
}

RegistrationSystem::~RegistrationSystem()
{
    if(students)
    {
        delete[] students;
    }

}
