//
//  Registrar.h
//  rec09
//
//  Created by Janina Soriano on 10/30/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#ifndef __rec09__Registrar__
#define __rec09__Registrar__

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

namespace BrooklynPoly
{
    class Course;
    class Student;
    
    class Registrar
    {
//        friend std::ostream& operator<< (std::ostream& os, const Registrar& rhs);
    public:
        Registrar();
        
        void printReport() const;
        void addCourse(const std::string& newCourse);
        void addStudent(const std::string& newStudent);
        void enrollStudentInCourse(const std::string& newStudent, const std::string& course);
        size_t findCourse(const std::string& course) const;
        size_t findStudent(const std::string& student) const;
        void cancelCourse(const std::string& course);
        void purge();

    
    private:
        std::vector<Course*> courses;
        std::vector<Student*> students;
        
    
    };
}

#endif /* defined(__rec09__Registrar__) */
