#ifndef __REGISTRATION_SYSTEM_H
#define __REGISTRATION_SYSTEM_H
#include "SimpleStudent.h"
#include <string>
#include<iostream>
using namespace std;

class RegistrationSystem
{
public:
    RegistrationSystem();
    ~RegistrationSystem();
    void addStudent( const int studentId, const string firstName, const string lastName );
    void deleteStudent( const int studentId );
    void showStudent( const int studentId );
    void showAllStudents();
    void sortStudentsArray();

private:
    Student *students;
    unsigned int noOfStudents;

};


#endif

