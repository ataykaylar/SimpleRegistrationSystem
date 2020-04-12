#include "SimpleStudent.h"

Student ::Student (const string sFirstName, const string sLastName,
                   const unsigned int sId)
{
    stuId = sId;
    stuFirstName = sFirstName;
    stuLastName = sLastName;


}

string Student::getStudentFirstName() const
{
    return stuFirstName;
}
string Student::getStudentLastName() const
{
    return stuLastName;
}

int Student::getStudentId() const
{
    return stuId;
}





Student::~Student ()
{

}
