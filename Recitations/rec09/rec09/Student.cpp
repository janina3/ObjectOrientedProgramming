//
//  Student.cpp
//  rec09
//
//  Created by Janina Soriano on 10/30/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#include "Student.h"
#include "Course.h"

using namespace std;
using namespace BrooklynPoly;

Student::Student(const string& theName) : name(theName) {}

void Student::display() const
{
    cout << "Name: " << endl;
}

string Student::getName() const
{
    return name;
}

vector<Course*> Student::getCourse() const
{
    return courses;
}

void Student::addCourse(Course* newCourse)
{
    courses.push_back(newCourse);
}

void Student::displayCourses() const
{
    for(size_t i = 0; i < courses.size(); i++)
    {
        cout << courses[i]->getName() << endl;
    }
}



/*
class Student
{
public:
    Student(const string& theName) : name(theName) {}
 
    void display() const
    {
        cout << "Name: " << endl;
    }
    
    string getName() const
    {
        return name;
    }
    
    vector<Course*> getCourse()
    {
        return courses;
    }
    
    void addCourse(Course* newCourse)
    {
        courses.push_back(newCourse);
    }
    
    void displayCourses()
    {
        for(size_t i = 0; i < courses.size(); i++)
        {
            cout << courses[i]->getName();
        }
    }
        
private:
    string name;
    vector<Course*> courses;
};
 
*/

