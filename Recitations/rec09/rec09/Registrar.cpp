//
//  Registrar.cpp
//  rec09
//
//  Created by Janina Soriano on 10/30/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#include "Registrar.h"
#include "Student.h"
#include "Course.h"

using namespace std;
using namespace BrooklynPoly;

Registrar::Registrar() {}
    
void Registrar::printReport() const //or overload the output operator
{
    for(size_t i = 0; i < courses.size(); i++)
    {
        cout << "Course: " << courses[i]->getName() << endl;

        cout << "Students: " << endl;
        courses[i]->displayStudents();
    }
    cout << endl;
    
    for(size_t i = 0; i < students.size(); i++)
    {
        cout << "Student: " << students[i]->getName() << endl;
        
        cout << "Courses: " << endl;
        students[i]->displayCourses();
    }
}

void Registrar::addCourse(const string& newCourse)
{
    Course* coursePtr = new Course(newCourse);
    courses.push_back(coursePtr);
}
    
void Registrar::addStudent(const string& newStudent)
{
    Student* studentPtr = new Student(newStudent);
    students.push_back(studentPtr);
}
    
void Registrar::enrollStudentInCourse(const string& newStudent, const string& course)
{
    if(findStudent(newStudent) < students.size())
    {
        courses[findCourse(course)]->addStudent(students[findStudent(newStudent)]);
        students[findStudent(newStudent)]->addCourse(courses[findCourse(course)]);

    }
}
    
size_t Registrar::findStudent(const string& student) const
{
    for(size_t i = 0; i < students.size(); i++)
    {
        if(students[i]->getName() == student)
        {
            return i;
        }
    }
        
    return students.size() + 1;
}
    
size_t Registrar::findCourse(const string& course) const
{
    for(size_t i = 0; i < courses.size(); i++)
    {
        if(courses[i]->getName() == course)
        {
            return i;
        }
    }
        
    return courses.size() + 1;
}

void Registrar::cancelCourse(const string& course)
{
    delete courses[findCourse(course)];
    for(size_t i = findCourse(course); i < courses.size(); i++)
    {
        courses[i] = courses[i + 1];
    }
    courses.pop_back();
}

void Registrar::purge()
{
    for(size_t i = 0; i < students.size(); i++)
    {
        delete students[i];
    }
    students.clear();
    
    for(size_t i = 0; i < courses.size(); i ++)
    {
        delete courses[i];
    }
    courses.clear();
}

//ostream& Registrar::operator<< (ostream& os, const Registrar& rhs)
//{
//    for(size_t i = 0; i < rhs.courses.size(); i++)
//    {
//        os << "Course: " << rhs.courses[i]->getName() << endl;
//        
//        os << "Students: " << endl;
//        rhs.courses[i]->displayStudents();
//    }
//}
