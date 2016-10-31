//
//  rec12.cpp
//  rec12
//
//  CS 1124
//  N14209086
//
//  Created by Janina Soriano on 11/20/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#include <iostream>
//#include <cstdlib> // To allow NULL if no other includes

using namespace std;

struct Node
{
    Node(int data = 0, Node* link = nullptr) : data(data), link(link) {}
    int data;
    Node* link;
};

void listInsertHead(int entry, Node*& headPtr)
{
    headPtr = new Node(entry, headPtr);
}

void spliceList(Node*& before, Node* insert)
{
    Node* n = before->link;
    before->link = insert;
    
    Node* current = insert;
    while(current->link != nullptr)
    {
        current = current->link;
    }
    
    current->link = n;
}

Node* find(Node* target, int index) //returns Node* at given index
{
    for(size_t i = 0; i < index - 1; i++)
    {
        target = target->link;
    }
    return target;
}

Node* findVal(Node* target, int data)
{
    Node* p = target;
    while(p)
    {
        if(p->data == data)
        {
            return p;
        }
        
        p = p->link;
    }
    
    return nullptr;
}

int size(Node* target)
{
    int size = 0;
    while(target != nullptr)
    {
        size++;
        target = target->link;
    }
    return size;
}

Node* isSublist(Node* base, Node* sub)
{
    Node* b = findVal(base, sub->data);
    Node* s = sub;
    int initialB = size(b);
    int initialS = size(s);
    int counterB = 0;
    int counterS = 0;
    
    while(b) //while b is not null
    {
        while(s != nullptr)    //if values are matching, and neither Node is null, advance
        {
            if((b->data == s->data) && (counterB == initialB || counterS == initialS))
            {
                return b;
            }
            
            else
            {
                b = b->link;
                s = s->link;
            }
                
            counterB++;
            counterS++;
        }
        
        if(counterB == initialB || counterS == initialS)
        {
            return b;
        }
        
    }
    
    return nullptr;
}

//isPrefix()
//run down sub, finding a match to first in base
//two pointers running down both lists
//while both aren't nullptrs, check match, if no match, return false, otherwise, bump both pointers
//outside of while loop, return whether sublist pointer reached the end of the list
    //if it did not reach the end of sub but it reached the end of base, then it is not a sublist

//isSublist()
//iterator pointer for base
//as long as base pointer isn't null, does the sublist start there
    //use isPrefix(), starting at bp, and bumping if isPrefix() returns false

/*
 while(bp)
 {
    if(isPrefix(bp, sub))
        return true;
    bp = bp->next;
 }
 
 return false;
 
 */




/*
Node* isSublist(Node* base, Node* sub)
{
    Node* a = base;
    Node* b = sub;
//    cout << "A: " << a->data << endl;
//    cout << "B: " << b->data << endl;
    
    for(int i = 0; i < size(base); i++) //iterating through base
    {
        a = find(base, i + 1);
//        cout << "A: " << a->data << endl;
//        cout << "B: " << b->data << endl;
        
        int initialA = size(a);
        int initialB = size(b);
        
        if(a->data == b->data)  //if sub is possibly found
        {
            for(int j = 0; j < initialB; j++)  //iterating through sub
            {
                for(int k = 0; k < initialA; k++)    //iterating through portion of base
                {
//                    if(a->data != b->data)  //if the data stops equaling each other, break
//                    {
//                        break;
//                    }
                    while(a->data == b->data)
                    {
                        a = find(a, j + 1);
                        b = find(b, k + 1);
                        
                        if(b->link == nullptr)
                        {
                            return a;
                        }
                    }
                    
                    if(a->data != b->data)
                    {
                        break;
                    }
                    
                }
            }
        }
    }
        
        
//        if(a->data == b->data)
//        {
//            while(b->link != nullptr)
//            {
//                if(a->data != b->data)
//                {
//                    break;
//                }
//                cout << "A: " << a->data << endl;
//                cout << "B: " << b->data << endl;
//                a = a->link;
//                b = b->link;
//            }
//            
//            if(b->link == nullptr && b->data == a->data)
//            {
//                return find(base, i + 1);
//            }
//            else
//            {
//                break;
//            }
//        }
//    }
    
//    while(a->data != b->data)
//    {
//        a = a->link;
//        cout << "A: " << a->data << endl;
//        cout << "B: " << b->data << endl;
//    }
//    
//    while(a->link != nullptr && b->link != nullptr)
//    {
//        if(a->data != b->data)
//        {
//            a = a->link;
//            b = sub;
//        }
//        else
//        {
//            a = a->link;
//            b = b->link;
//            cout << "A: " << a->data << endl;
//            cout << "B: " << b->data << endl;
//        }
//    }
    
    return nullptr;
}
 
*/

void display(Node* headPtr)
{
    Node* current = headPtr;
    while(current != nullptr)
    {
        cout << current->data << " ";
        current = current->link;
    }
}

int main()
{   /*
    cout << "Part 1: " << endl;
    cout << endl;
    
    Node* list1 = nullptr;
    listInsertHead(1, list1);
    listInsertHead(9, list1);
    listInsertHead(7, list1);
    listInsertHead(5, list1);
    
    cout << "L1: ";
    
    display(list1);
    cout << endl;
    
    Node* list2 = nullptr;
    listInsertHead(2, list2);
    listInsertHead(3, list2);
    listInsertHead(6, list2);
    
    cout << "L2: ";
    
    display(list2);
    cout << endl;
    
    Node* target = find(list1, 4);
    
    cout << "Target: ";
    display(target);
    cout << endl;
    
    cout << "Splicing L2 at target in L1" << endl;
    spliceList(target, list2);
    
    cout << "New L1: ";
    display(list1);
    cout << endl;
    
    cout << "New L2: ";
    display(list2);
    cout << endl;
    
    cout << "====================================" << endl;
    
    cout << "Part 2: " << endl;
    cout << endl;
    */
    Node* base = nullptr;
    listInsertHead(6, base);
    listInsertHead(5, base);
    listInsertHead(4, base);
    listInsertHead(2, base);
    listInsertHead(3, base);
    listInsertHead(2, base);
    listInsertHead(3, base);
    listInsertHead(2, base);
    listInsertHead(1, base);
    
    
    cout << "Target: ";
    display(base);
    cout << endl;
    
    Node* case1 = nullptr;
    listInsertHead(1, case1);
    cout << "Attempt Match 1: ";
    display(case1);
    cout << endl;
    if(isSublist(base, case1) == nullptr)
    {
        cout << "Failed to match" << endl;
    }
    else
    {
        display(isSublist(base, case1));
        cout << endl;
    }
    cout << endl;
    
    
    Node* case2 = nullptr;
    listInsertHead(9, case2);
    listInsertHead(3, case2);
    cout << "Target: ";
    display(base);
    cout << endl;
    cout << "Attempt Match: ";
    display(case2);
    cout << endl;
    if(isSublist(base, case2) == nullptr)
    {
        cout << "Failed to match" << endl;
    }
    else
    {
        display(isSublist(base, case2));
        cout << endl;
    }
    cout << endl;
    
    Node* case3 = nullptr;
    listInsertHead(3, case3);
    listInsertHead(2, case3);
    cout << "Target: ";
    display(base);
    cout << endl;
    cout << "Attempt Match: ";
    display(case3);
    cout << endl;
    if(isSublist(base, case3) == nullptr)
    {
        cout << "Failed to match" << endl;
    }
    else
    {
        display(isSublist(base, case3));
        cout << endl;
    }
    cout << endl;

    Node* case4 = nullptr;
    listInsertHead(6, case4);
    listInsertHead(5, case4);
    listInsertHead(4, case4);
    listInsertHead(2, case4);
    cout << "Target: ";
    display(base);
    cout << endl;
    cout << "Attempt Match: ";
    display(case4);
    cout << endl;
    if(isSublist(base, case4) == nullptr)
    {
        cout << "Failed to match" << endl;
    }
    else
    {
        display(isSublist(base, case4));
        cout << endl;
    }
    cout << endl;

    Node* case5 = nullptr;
    listInsertHead(4, case5);
    listInsertHead(2, case5);
    listInsertHead(3, case5);
    listInsertHead(2, case5);
    cout << "Target: ";
    display(base);
    cout << endl;
    cout << "Attempt Match: ";
    display(case5);
    cout << endl;
    if(isSublist(base, case5) == nullptr)
    {
        cout << "Failed to match" << endl;
    }
    else
    {
        display(isSublist(base, case5));
        cout << endl;
    }
    cout << endl;

    Node* case6 = nullptr;
    listInsertHead(7, case6);
    listInsertHead(6, case6);
    listInsertHead(5, case6);
    cout << "Target: ";
    display(base);
    cout << endl;
    cout << "Attempt Match: ";
    display(case6);
    cout << endl;
    if(isSublist(base, case6) == nullptr)
    {
        cout << "Failed to match" << endl;
    }
    else
    {
        display(isSublist(base, case6));
        cout << endl;
    }
}
