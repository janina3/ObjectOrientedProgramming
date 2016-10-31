//
//  Course.h
//  rec09
//
//  Created by Janina Soriano on 10/30/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#ifndef __rec09__Course__
#define __rec09__Course__

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

namespace BrooklynPoly
{
    class Student;
    
    class Course
    {
    public:
        Course (const std::string& theName);
        
        void display() const;
        std::string getName() const;
        std::vector<Student*> getStudents() const;
        void addStudent(Student* newStudent);
        void displayStudents() const;
        
    private:
        std::string name;
        std::vector<Student*> students;
        
    };

}

#endif /* defined(__rec09__Course__) */
