//
//  main.cpp
//  rec07
//
//  CS 1124
//  N14209086
//
//  Created by Janina Soriano on 10/16/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class PrintedMaterial {
public:
    PrintedMaterial(unsigned numPages) : numberOfPages(numPages){};
    
    virtual void displayNumPages() const = 0;
    
protected:
private:
    unsigned numberOfPages;
};

void PrintedMaterial::displayNumPages() const
{
    cout << numberOfPages << endl;
}

class Magazine : public PrintedMaterial {
public:
    Magazine(unsigned numPages) : PrintedMaterial(numPages) {};
    
    void displayNumPages() const
    {
        PrintedMaterial::displayNumPages();
    }
    
protected:
private:
};

class Book : public PrintedMaterial {
public:
    Book(unsigned numPages) : PrintedMaterial(numPages) {};
    
    void displayNumPages() const
    {
        PrintedMaterial::displayNumPages();
    }
    
protected:
private:
};

class TextBook : public Book {
public:
    TextBook(unsigned numPages, unsigned numIndxPgs) : Book(numPages), numOfIndexPages(numIndxPgs) {};
    
    void displayNumPages() const
    {
        cout << "Number of pages: ";
        Book::displayNumPages();
        cout << "Number of index pages: " << numOfIndexPages << endl;
    }
protected:
private:
    unsigned numOfIndexPages;
};

class Novel : public Book {
public:
    Novel(unsigned numPages) : Book(numPages) {};

protected:
private:
};

void displayNumberOfPages(const PrintedMaterial& printedMat)
{
    printedMat.displayNumPages();
}

// tester/modeler code
int main()
{
    TextBook t(5430, 23);
    Novel n(213);
    Magazine m(6);
    
    t.displayNumPages();
    n.displayNumPages();
    m.displayNumPages();
    
    cout << "\nA PrintedMaterial material object!\n";
//    PrintedMaterial pm(2345);
//    pm.displayNumPages();
    
//    pm = t; // like putting a t into a vector of PrintedMaterials
//    pm.displayNumPages();
    
//    cout << "\nUsing PrintedMaterial* to \"store\" a TextBook object\n";
//    cout << "Now with the virtual mechanism involved\n";
//    // should work now that the virtual mechanism is being invoked
//    PrintedMaterial* pmPtr;
//    pmPtr = &t; // like putting t into a vector but
//    // we are actually putting the address of t
//    // into a vector pointers of pointers to
//    // PrintedMaterials. We'll "say" we are putting
//    pmPtr->displayNumPages();
    
    // print some stuff by calling a generic function
    cout << "\nUse a generic functino for printing\n";
    displayNumberOfPages(m);
    displayNumberOfPages(n);
    displayNumberOfPages(t);
    
    vector<PrintedMaterial*> allMaterials;
    allMaterials.push_back(&t);
    allMaterials.push_back(&n);
    allMaterials.push_back(&m);
    
    for(PrintedMaterial* pm : allMaterials)
    {
        pm->displayNumPages();
    }
    
}