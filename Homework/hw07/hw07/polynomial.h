//
//  polynomial.h
//  hw07
//
//  Created by Janina Soriano on 12/7/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#include <iostream>
#include <vector>


#ifndef hw07_polynomial_h
#define hw07_polynomial_h

struct Node //create nodes for linked lists
{
    int data;
    Node* next;
    Node(int d = 0, Node* l = nullptr);
};


class Polynomial
{
public:
    Polynomial(const std::vector<int>& coefficient);
    
    Polynomial();
    
    //    Node* getHeadPtr() const;
    //    int getDegree() const;
    
    //operators
    //use friend operators when a class is going to be on the right side of the operator
    //that does not provide an implicit conversion to a type that can be compared to the left side
    
    //plus-equals operator
    Polynomial& operator+= (const Polynomial& rhs);
    
    //assignment operator
    Polynomial& operator= (const Polynomial& rhs);
    
    //copy constructor
    Polynomial(const Polynomial& rhs);
    
    //destructor
    ~Polynomial();
    
    //equals-equals operator
    bool operator== (const Polynomial& rhs);
    
    //does-not-equal operator
    bool operator!= (const Polynomial& rhs);
    
    
    friend std::ostream& operator<< (std::ostream& os, const Polynomial& rhs);
    
    
    
    
    int evaluate(int value);
    
    
private:
    Node* headPtr = nullptr;
    int degree;
    
    
};


std::ostream& operator<< (std::ostream& os, const Polynomial& rhs);



//plus operator
Polynomial operator+ (const Polynomial& lhs, const Polynomial& rhs);


#endif
