//
//  Student.h
//  rec09
//
//  Created by Janina Soriano on 10/30/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#ifndef __rec09__Student__
#define __rec09__Student__

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

namespace BrooklynPoly
{
    class Course;
    
    class Student
    {
    public:
        Student(const std::string& theName);
        
        void display() const;
        std::string getName() const;
        std::vector<Course*> getCourse() const;
        void addCourse(Course* newCourse);
        void displayCourses() const;
    
    private:
        std::string name;
        std::vector<Course*> courses;
    };
}

#endif /* defined(__rec09__Student__) */
