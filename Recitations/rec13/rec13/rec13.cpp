//
//  rec13.cpp
//  rec13
//
//  N14209086
//  CS 1124
//
//  Created by Janina Soriano on 12/4/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
};

class Sequence
{
public:
    Sequence() : headPtr(nullptr), current(nullptr) {}
    
    //Copy Constructor
    Sequence(const Sequence& anotherSeq)
    {
        headPtr = new Node(anotherSeq.headPtr->data);
        Node* p = anotherSeq.headPtr;
        Node* c = headPtr;
        while(p->next != nullptr)
        {
            p = p->next;
            c->next = new Node(p->data);
            c = c->next;
            
        }
        c = new Node(p->data);
        current = c;
    }
    
    //Assignment Operator
    Sequence& operator=(const Sequence& rhs)
    {
        //this->reset();
        this->clear();
        
        headPtr = new Node(rhs.headPtr->data);
        Node* p = rhs.headPtr;
        Node* c = headPtr;
        while(p->next != nullptr)
        {
            p = p->next;
            c->next = new Node(p->data);
            c = c->next;
        }
        c = new Node(p->data);
        current = c;
        
        return *this;
    }
    
    //Destructor
    ~Sequence()
    {
        this->clear();
    }
    
    void reset()
    {
        current = headPtr;
    }
    
    void add(int newData)
    {
        if(headPtr == nullptr)
        {
            headPtr = new Node(newData);
            this->reset();
        }
        else if(this->valid())
        {
            Node* p = current->next;
            current->next = new Node(newData);
            current = current->next;
            current->next = p;

        }
    }
    
    void remove()
    {
        if(current == nullptr)
        {
            return;
        }
        else if(current->next == nullptr)   //if current is pointing to the last element
        {
            Node* c = headPtr;
            while(c->next != current)
            {
                c = c->next;
            }
            delete current;
            current = c;
            //current->next = nullptr;

        }
        else
        {
            Node* c = headPtr;
            cout << headPtr->data << endl;
            while(c->next != current && c != nullptr)
            {
                c = c->next;
                
                if(c == nullptr)
                {
                    break;
                }
//                if(c->next == nullptr)
//                {
//                    break;
//                }
            }
            
            if(c->next != nullptr)
            {
                c->next = current->next;
            }
            delete current;
            current = c;
        }
    }
    
    void display()
    {
        if(headPtr == nullptr)
        {
            cout << endl;
            return;
        }
        this->reset();
        while(this->valid())
        {
            cout << this->data() << " ";
            current = current->next;
        }
        
        cout << endl;
    }
    
    void clear()
    {
        if(headPtr == nullptr)
            return;
        while(current != nullptr)
        {
            this->remove();
        }
        delete headPtr;
        headPtr = nullptr;
    }
    
    bool valid()
    {
        return current;
    }
    
    int data()
    {
        return current->data;
    }
    
    void next()
    {
        if(current == nullptr)
            return;
        current = current->next;
    }
    
private:
    Node* headPtr;
    Node* current;
    
    
    
};

int main()
{
    Sequence s;
    for (int i = 0; i < 6; ++i) s.add(i);
    s.display();
    cout << "==========\n";
    s.reset();
    for (int i = 0; i < 3; ++i) s.next();
    s.add(42);
    s.display();
    cout << "==========\n";
    s.reset();
    for (int i = 0; i < 2; ++i) s.next();
    s.remove();
    s.display();
    cout << "==========\n";
    s.clear();
    s.display();
    cout << "==========\n";
    
    cout << endl;
    
    cout << "Test Copy Constructor:" << endl;
    
    Sequence a;
    for (int i = 0; i < 6; ++i) a.add(i);
    cout << "Original: ";
    a.display();
    Sequence b = a;
    cout << "Copy: ";
    b.display();
    
    cout << endl;
    
    cout << "Test Assignment Operator: " << endl;
    cout << "Original: ";
    a.display();
    
    Sequence c;
    for (int i = 0; i < 4; ++i) c.add(i);
    
//    cout << "Replace: ";
//  c.display();

    c = a;
    cout << "Result: ";
    c.display();

    
    
}