//
//  Course.cpp
//  rec09
//
//  Created by Janina Soriano on 10/30/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#include "Course.h"
#include "Student.h"

using namespace std;
using namespace BrooklynPoly;

Course::Course(const string& theName) : name(theName) {}

void Course::display() const
{
    cout << "Name: " << name;
}

string Course::getName() const
{
    return name;
}

vector<Student*> Course::getStudents() const
{
    return students;
}

void Course::addStudent(Student* newStudent)
{
    students.push_back(newStudent);
}

void Course::displayStudents() const
{
    for(size_t i = 0; i < students.size(); i++)
    {
        cout << students[i]->getName() << endl;
    }
}


/*
class Course
{
public:
    Course (const string& theName) : name(theName) {}
    
    void display() const
    {
        cout << "Name: " << name;
    }
    
    string getName() const
    {
        return name;
    }
    
    vector<Student*> getStudents()
    {
        return students;
    }
    
    void addStudent(Student* newStudent)
    {
        students.push_back(newStudent);
    }
    
    void displayStudents()
    {
        for(size_t i = 0; i < students.size(); i++)
        {
            cout << students[i]->getName();
        }
    }
    
private:
    string name;
    vector<Student*> students;
    
};*/
