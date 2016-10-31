//
//  polynomial.cpp
//  hw07
//
//  N14209086
//  CS 1124
//
//  Created by Janina Soriano on 12/7/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#include "polynomial.h"
#include "math.h"

using namespace std;

Node::Node(int d, Node* n) : data(d), next(n) {};

void listDisplay(const Node* headPtr)
{
    //declare temp variable
    const Node* p = headPtr;
    
    //loop through list
    //if p is a nullptr, we're not pointing to a node anymore
    while(p != nullptr)
    {
        cout << p->data << ' ';
        
        //Bump the pointer
        //CANNOT do p++
        //linked lists aren't stored in the correct order like arrays
        p = p->next;
    }
    cout << endl;
}

void listInsertHead(Node*& headPtr, int value)
{
    Node* temp = new Node(value);
    temp->next = headPtr;
    headPtr = temp;
}

Node* listFindLast(Node* headPtr)
{
    if (headPtr == nullptr)
    {
        return nullptr;
    }
    
    Node* p = headPtr;
    
    while (p->next != nullptr)
    {
        p = p->next;
    }
    return p;
}

void listAddTail(Node*& headPtr, int data)
{
    if (headPtr == nullptr)
    {
        headPtr = new Node(data);
    }
    else
    {
        Node* last = listFindLast(headPtr);
        last->next = new Node(data);
    }
}

//void listInsertAfter(Node* previousPtr, int entry)
//{
//    //create a new node on the heap
//    Node* temp = new Node;
//
//    //Place the new entry in the new node
//    temp->data = entry;
//
//    //make the new node point to the node after previousPtr
//    temp->link = previousPtr->link;
//
//    //make previousPtr's node point to the new node
//    previousPtr->link = temp;
//}


Polynomial::Polynomial(const vector<int>& coefficient)
{
    degree = coefficient.size()- 1;
    
    //put all the coefficients in a linked list
    //the vector is from highest to lowest degree
    //linked list should be lowest to highest degree
    for(int item : coefficient)                //for each item in the vector, add it to the headPtr using insert head
    {
        listInsertHead(headPtr, item);
    }
    
};

Polynomial::Polynomial()
{
    degree = 0;
    //put all the coefficients in a linked list
    //the vector is from highest to lowest degree
    //linked list should be lowest to highest degree
    headPtr = new Node(0);
    
};

//Node* Polynomial::getHeadPtr() const
//{
//    return headPtr;
//}
//
//int Polynomial::getDegree() const
//{
//    return degree;
//}


//operators
//use friend operators when a class is going to be on the right side of the operator
//that does not provide an implicit conversion to a type that can be compared to the left side
//put friend in the header

//plus-equals operator
Polynomial& Polynomial::operator+= (const Polynomial& rhs)
{
    if(!rhs.headPtr)
    {
        return *this;
    }
    
    Node* h = headPtr;
    Node* r = rhs.headPtr;
    
    if(rhs.degree > degree)
    {
        for(int i = 0; i < (rhs.degree - degree) + 1; i++)
        {
            listAddTail(headPtr, 0);
        }
        degree = rhs.degree;
    }
    
    while (r)
    {
        h->data = r->data + h->data;
        h = h->next;
        r = r->next;
    }
    
    return *this;
    
}

//assignment operator
Polynomial& Polynomial::operator= (const Polynomial& rhs)
{
    if(*this != rhs)
    {
        while(headPtr)
        {
            Node* temp = headPtr;
            headPtr = headPtr->next;
            delete temp;
        }
        Node* r = rhs.headPtr;
        headPtr = new Node(r->data);
        Node* temp = headPtr;
        degree = rhs.degree;
       
        r = r->next;
        
        while(r)
        {
            temp->next = new Node(r->data);
            temp = temp->next;
            r = r->next;
        }
        
    }
    
    return *this;
}

//plus operator
Polynomial operator+ (const Polynomial& lhs, const Polynomial& rhs)
{
    Polynomial sum(lhs);
    sum += rhs;
    return sum;
}

//copy constructor
Polynomial::Polynomial(const Polynomial& rhs)
{
    degree = rhs.degree;
    Node* r = rhs.headPtr;
    headPtr = new Node(r->data);    //deepcopy
    Node* head = headPtr;
    r = r->next;
    while(r)
    {
        head->next = new Node(r->data);
        head = head->next;
        r = r->next;
    }
}

//destructor
Polynomial::~Polynomial()
{
    for(int i = 0; i < (degree + 1); i++)
    {
        if(headPtr == nullptr)
            break;
        
        Node* first = headPtr;
        Node* second = headPtr->next;
        
        while(second)
        {
            delete first;
            first = second;
            second = second->next;
        }
        delete first;
        headPtr = nullptr;
    }
}

//equals-equals operator
bool Polynomial::operator== (const Polynomial& rhs)
{
    if (degree == rhs.degree)
    {
        Node* h = headPtr;
        Node* r = rhs.headPtr;
        
        while(h && r)
        {
            if (h->data == r->data)
            {
                h = h->next;
                r = r->next;
            }
            else
            {
                return false;
            }
        }
        
        return true;
    }
    else
    {
        return false;
    }
}

//does-not-equal operator
bool Polynomial::operator!= (const Polynomial& rhs)
{
    return !(*this == rhs);
}

ostream& operator<< (ostream& os, const Polynomial& rhs)
{
    //int degree = 0;
    Node* r = rhs.headPtr;
    
    if(rhs.degree == 0)
    {
        os << r->data;
    }
    else
    {
        for(int i = 0; i < rhs.degree; i++)
        {
            if(i == 0)
            {
                os << r->data << "+";
                r = r->next;
            }
            else
            {
                os << r->data << "x^" << i << "+";
                r = r->next;
            }
        }
        if(rhs.degree > 0)
            os << r->data << "x^" << rhs.degree;
        return os;
    }
    
    return os;
}

int Polynomial::evaluate(int value)
{
    double val = 0;
    Node* h = headPtr;
    int counter = 0;
    while(h)
    {
        val += h->data*(pow(value, counter));
        counter += 1;
        h = h->next;
    }
    return val;
}
