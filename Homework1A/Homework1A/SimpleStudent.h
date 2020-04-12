#ifndef __SIMPLE_STUDENT_H
#define __SIMPLE_STUDENT_H
#include <string>
using namespace std;
class Student
{
    public:
    Student(const string sFirstName = "", const string sLastName = "",
         const unsigned int sId = 0);
    ~Student();
    string getStudentFirstName() const;
    string getStudentLastName() const;
    int getStudentId() const;
    bool printStudent(const int courseId);

private:
    int stuId;
    string stuFirstName;
    string stuLastName;

};

#endif
