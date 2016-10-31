 //
//  rec10.cpp
//  rec10
//
//  N14209086
//  CS1124
//
//  Created by Janina Soriano on 11/6/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#include <string>
#include <iostream>
using namespace std;

class Position
{
public:
    Position(const string& aTitle, double aSalary) : title(aTitle), salary(aSalary) {}
    
    string getTitle() const
    {
        return title;
    }
    
    double getSalary() const
    {
        return salary;
    }
    
    void changeSalaryTo(double d)
    {
        salary = d;
    }
    
private:
    string title;
    double salary;
}; // class Position

class Entry
{
public:
    Entry(const string& aName, unsigned aRoom, unsigned aPhone, Position& aPosition) : name(aName), room(aRoom), phone(aPhone), pos(&aPosition) {}
    
    friend ostream& operator<<( ostream& os, const Entry& e )
    {
        os << e.name << ' ' << e.room << ' ' << e.phone;
        return os;
    } // operato<<
    
    //Accessors
    string getName()
    {
        return name;
    }
    
    unsigned getPhone()
    {
        return phone;
    }
    
private:
    string name;
    unsigned room;
    unsigned phone;
    Position* pos;
}; // class Entry

class Directory
{
    
    friend ostream& operator<<(ostream& os, const Directory& dir);
    
public:
    Directory() : capacity(2), size(0), entries(new Entry*[2] )
    {
        // Should we do this?  What do you think?
        for (size_t i = 0; i < capacity; i++)
        {
            entries[i] = nullptr;
        } // for
        
    } // Directory()
    
    //Copy Constructor
    Directory(const Directory& anotherDir)
    {
        cout << "Copy Constructor" << endl;
        entries = new Entry*[anotherDir.capacity];
        for(size_t i = 0; i < anotherDir.size; i++)
        {
            entries[i] = new Entry(*anotherDir.entries[i]);
        }
        size = anotherDir.size;
        capacity = anotherDir.capacity;
        
    }
    
    //Assignment Operator
    Directory& operator= (const Directory& rhs)
    {
        cout << "Assignment Operator" << endl;
        for(size_t i = 0; i < size; i++)
        {
            delete entries[i];
        }
        delete [] entries;
        entries = new Entry*[rhs.capacity];
        for(size_t i = 0; i < rhs.size; i++)
        {
            entries[i] = new Entry(*rhs.entries[i]);
        }
        size = rhs.size;
        capacity = rhs.capacity;
        return *this;
        
    }
    
    //Destructor
    ~Directory()
    {
        cout << "Destructor" << endl;
        for(size_t i = 0; i < size; i++)
        {
            delete entries[i];
        }
        delete [] entries;
    }
    
    void add(const string& name, unsigned room, unsigned ph, Position& pos) {
        if( size == capacity )
        {
            //Make the array grow
            size_t newCapacity = 2 * capacity + 1;
            
            //Allocate a new array on the heap
            Entry** newEntry = new Entry*[newCapacity];
            
            //Copy info from old array into new array
            for(size_t i = 0; i < size; i++)
            {
                newEntry[i] = new Entry(*entries[i]);
            }
            
            //Delete entire array on the heap
            
            for(size_t i = 0; i < size; i++)
            {
                delete entries[i];
            }
            delete [] entries;
            entries = newEntry;
            capacity = newCapacity;
            
        } // if
        entries[size] = new Entry(name, room, ph, pos);
        ++size;
    } // add
    
    unsigned operator[](const string& name) const
    {
        for(size_t i = 0; i < size; i ++)
        {
            if(entries[i]->getName() == name)
            {
                return entries[i]->getPhone();
            }
        }
        
        return 0;
    }

    
private:
    Entry** entries;
    size_t size;
    size_t capacity;
}; // class Directory

ostream& operator<<(ostream& os, const Directory& dir)
{
    for(size_t i = 0; i < dir.size; i++)
    {
        os << *dir.entries[i];
        os << endl;
    }
    
    return os;
}


void doNothing(Directory dir) { cout << dir << endl; }

int main() {
    
    // Model as if there are these four kinds
    // of position in the problem:
    Position boss("Boss", 3141.59);
    Position pointyHair("Pointy Hair", 271.83);
    Position techie("Techie", 14142.13);
    Position peon("Peonissimo", 34.79);
    
    // Create a Directory
    Directory d;
    d.add("Marilyn", 123, 4567, boss);
    cout << d << endl;
    
    Directory d2 = d;	// What function is being used??
    d2.add("Gallagher", 111, 2222, techie);
    d2.add("Carmack", 314, 1592, techie);
    cout << d2 << endl;
    
    cout << "Calling doNothing\n";
    doNothing(d2);
    cout << "Back from doNothing\n";
    
    Directory d3;
    d3 = d2;
    
    cout << "Find Marilyn's phone number" << endl;
    cout << d["Marilyn"] << endl;
    
} // main
