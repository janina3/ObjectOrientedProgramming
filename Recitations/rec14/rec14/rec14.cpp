//
//  rec14.cpp
//  rec14
//
//  N14209086
//  CS 1124
//
//  Created by Janina Soriano on 12/11/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#include <iostream>
#include <string>
#include <climits>

using namespace std;

struct Node
{
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};

void binary(int n)
{
    if(n < 2)
    {
        cout << n;
    }
    else
    {
        binary(n / 2);
        cout << n % 2;
    }
}

//pass in 2 lists, return a list of the sums
//assume lists have the same size
Node* sumList(Node* h1, Node* h2)
{
    if(h1->next== nullptr)
    {
        return new Node(h1->data + h2->data);
    }
    else
    {
        Node* p = new Node(h1->data + h2->data);
        p->next = sumList(h1->next, h2->next);
        return p;
    }
}

void printList(Node* headPtr)
{
    Node* p = headPtr;
    while(p != nullptr)
    {
        cout << p->data << ' ';
        p = p->next;
    }
    
    cout << endl;
}

struct TNode
{
    TNode(int data = 0, TNode* left = nullptr, TNode* right = nullptr) : data(data), left(left), right(right) {}
    int data;
    TNode* left;
    TNode* right;
};

int max(TNode* root)
{
    if(root == nullptr)
    {
        return INT_MIN;
    }
    
    if(root->data > max(root->left))
    {
        if(root->data > max(root->right))
        {
            return root->data;
        }
        
        return max(root->right);
    }
    
    else if(max(root->left) > max(root->right))
    {
        return max(root->left);
    }
    
    return max(root->right);
    
}

int cSum(const string& cstring, int i = 0)
{
    if(!cstring[i])
    {
        return 0;
    }
    return int(cstring[i]) + cSum(cstring, i+1);
}

int binarySearch(char target, char cArray[], int low, int high)
{
    if(low > high)
    {
        return -1;
    }
    
    int mid = low + (high - low) / 2;
    
    if(target == cArray[mid])
    {
        return mid;
    }
    else if(target < cArray[mid])
    {
        return binarySearch(target, cArray, low, mid-1);
    }
    else
    {
        return binarySearch(target, cArray, mid+1, high);
    }
    
}

void func(int n)
{
    if (n > 1)
    {
        cout << 'a';
        func(n/2);
        cout << 'b';
        func(n/2);
    }
    cout << 'c';
}

int main()
{
    //Task 1
    binary(5);
    cout << endl;
    
    //Task 2
    Node* h5 = new Node(5);
    Node* h4 = new Node(4, h5);
    Node* h3 = new Node(3, h4);
    Node* h2 = new Node(2, h3);
    Node* h1 = new Node(1, h2);
    
    Node* n5 = new Node(6);
    Node* n4 = new Node(5, n5);
    Node* n3 = new Node(4, n4);
    Node* n2 = new Node(3, n3);
    Node* n1 = new Node(2, n2);
    
    Node* sum = sumList(h1, n1);
    printList(h1);
    printList(n1);
    printList(sum);
    
    //Task 3
    TNode a(1), b(2), c(4), d(8, &a, &b), e(0, &c), f(3, &d, &e);
    cout << max(&f) << endl;

    //Task 4
    char cstring[15] = "I love C++";
    cout << cSum(cstring) << endl;
    
    //Task 5
    char dstring[] = "Today is Friday the eleventh of December";
//    sort(dstring, dstring + sizeof(dstring));
//    cout << binarySearch('d', dstring, 0, 40) << endl;
    for(char a : dstring)
        cout << a;
    sort(dstring, dstring + 40);
    for(char a : dstring)
        cout << a;
    cout << binarySearch('d', dstring, 0, 40) << endl;
    
    char astring[17] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q'};
    cout << binarySearch('H', astring, 0, 16) << endl;
    
    //Task 6
    func(7);
    
    cout << endl;

    
}