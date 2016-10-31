//
//  main.cpp
//  rec06
//
//  CS1124
//  N14209086
//
//  Created by Janina Soriano on 10/9/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class TimeSlot
{
public:
    TimeSlot(const string& theDay, int theHour) : day(theDay), hour(theHour) {};
    
    void display()
    {
        cout << day << " ";
        if(hour == 12)
        {
            cout << "12PM" << endl;
        }
        else if(hour == 0)
        {
            cout << "12AM" << endl; //There are most likely no 12AM sections
        }
        else if(hour < 12)
        {
            cout << hour << "AM" << endl;
        }
        else
        {
            cout << hour - 12 << "PM" << endl;
        }
    }
    
private:
    string day;
    int hour;
};

class StudentRecord
{
public:
    StudentRecord(const string& theName) : name(theName), grades(13, -1) {};
    
    void displayGrade()
    {
        cout << "Grades: ";
        for(size_t index = 0; index < grades.size() - 1; ++index)
        {
            cout << grades[index] << " ";
        }
        cout << endl;
        
    }
    void addGrade(int studentGrade, int sectionWeek)
    {
        for(size_t index = 0; index < grades.size() - 1; index++)
        {
          //  index = sectionWeek - 1;
            grades[sectionWeek - 1] = studentGrade;
        }
    }
    string getName()
    {
        return name;
    }
    
private:
    string name;
    vector<int> grades;
};

class Section
{
public:
    Section(const string& theName, const string& theDay, int theTime) : name(theName), time(theDay, theTime) {};
    
    void displayTime()
    {
        //calls TimeSlot displayTime
        time.display();
    }
    void displayGrades()
    {
        //calls StudentRecord display()
        for(size_t index = 0; index < students.size(); ++index)
        {
            cout << students[index]->getName() << "; ";
            students[index]->displayGrade();
        }
        
    }
    void addStudent(const string& studentName)
    {
        //StudentRecord newStudent(studentName);
        StudentRecord* s = new StudentRecord(studentName);
        students.push_back(s);
    }
    void addGrade(const string& studentName, int studentGrade, int sectionWeek)
    {
        //calls StudentRecord addGrade()
        for(size_t index = 0; index < students.size(); ++index)
        {
            if(studentName == students[index]->getName())
            {
                students[index]->addGrade(studentGrade, sectionWeek);
            }
        }
    }
    void display()
    {
        cout << "Section: " << name << "; ";
        //calls displayTime
        displayTime();
        //calls displayGrades
        displayGrades();
        cout << endl;
    }
    void reset()
    {
        for(StudentRecord* student : students)
        {
            delete student;
            student = nullptr;
        }
        students.clear();
    }
    
private:
    string name;
    TimeSlot time;
    vector<StudentRecord*> students;
    
};

class LabWorker
{
public:
    LabWorker(const string& theName) : name(theName) {};
    
    void displayGrades()
    {
        //calls Section displayGrade()
        section->display();
    }
    
    void addGrade(const string& studentName, int studentGrade, int week)
    {
        //calls Section addGrade()
        section->addGrade(studentName, studentGrade, week);
    }
    void addSection(Section& newSection)
    {
        section = &newSection;
    }
    
private:
    string name;
    Section* section;
    
};

int main()
{
    
    // lab workers
    LabWorker moe( "Moe" );
    LabWorker jane( "Jane" );
    
    // sections and setup and testing
    Section secA2( "A2", "Tuesday", 16 );
    //secA2.loadStudentsFromFile( "A2.txt" );
    secA2.addStudent("John");
    secA2.addStudent("George");
    secA2.addStudent("Paul");
    secA2.addStudent("Ringo");
    
    cout << "\ntest A2\n";    // here the modeler-programmer checks that load worked
    secA2.display();          // YOU'll DO THIS LATER AS: cout << secA2 << endl;
    moe.addSection( secA2 );
    moe.displayGrades();       // here the modeler-programmer checks that adding the Section worked
    
    Section secB3( "B3", "Thursday", 11 );
    //secB3.loadStudentsFromFile( "B3.txt" );
    secB3.addStudent("Thorin");
    secB3.addStudent("Dwalin");
    secB3.addStudent("Balin");
    secB3.addStudent("Kili");
    secB3.addStudent("Fili");
    secB3.addStudent("Dori");
    secB3.addStudent("Nori");
    secB3.addStudent("Ori");
    secB3.addStudent("Oin");
    secB3.addStudent("Gloin");
    secB3.addStudent("Bifur");
    secB3.addStudent("Bofur");
    secB3.addStudent("Bombur");
    
    cout << "\ntest B3\n";    // here the modeler-programmer checks that load worked
    secB3.display();          // YOU'll DO THIS LATER AS: cout << secB3 << endl;
    jane.addSection( secB3 );
    jane.displayGrades();      // here the modeler-programmer checks that adding Instructor worked
    
    
    // setup is complete, now a real world scenario can be written in the code
    // [NOTE: the modeler-programmer is only modeling joe's actions for the rest of the program]
    
    // week one activities
    cout << "\nModeling week: 1\n";
    moe.addGrade( "John", 7, 1 );
    moe.addGrade( "Paul", 9, 1 );
    moe.addGrade( "George", 7, 1 );
    moe.addGrade( "Ringo", 7, 1 );
    cout << "End of week one\n";
    moe.displayGrades();
    
    // week two activities
    cout << "\nModeling week: 2\n";
    moe.addGrade( "John", 5, 2 );
    moe.addGrade( "Paul", 10, 2 );
    moe.addGrade( "Ringo", 0, 2 );
    cout << "End of week two\n";
    moe.displayGrades();
    
    //test that reset works  // NOTE: can we check that the heap data was dealt with?
    cout << "\ntesting reset()\n";
    secA2.reset();
    secA2.display();
    moe.displayGrades();
     
    
} // main