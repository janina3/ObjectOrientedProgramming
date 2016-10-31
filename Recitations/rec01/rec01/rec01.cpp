//
//  rec01.cpp
//  rec01
//
//  Created by Janina Soriano on 9/4/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //open file
    ifstream ifsline("/Users/janinasoriano/Documents/School Work/Fall 2015/CS 1124/rec/rec01/rec01/jabberwocky.txt");
    //check if file opened
    if(!ifsline)
    {
        cerr << "Couldn't open file" << endl;
        exit(1);
    }
    
    string line;
    int lineCounter = 0;
    
    //prints each line and counts the lines
    while(getline(ifsline, line))
    {
        lineCounter++;
        cout << line << endl;
    }
    
    //cout << endl;
    
    //close file
    ifsline.close();
    
    //open file
    ifstream ifsword("/Users/janinasoriano/Documents/School Work/Fall 2015/CS 1124/rec/rec01/rec01/jabberwocky.txt");
    //check if file is opened
    if(!ifsword)
    {
        cerr << "Couldn't open file" << endl;
        exit(2);
    }
    
    string word;
    int wordCounter = 0;
    
    //counts the words
    while(ifsword >> word)
    {
        //ifsword >> word;
        wordCounter++;
        //cout << word << endl;
    }
    
    //cout << endl;
    
    //close file
    ifsword.close();
    
    //open file
    ifstream ifschar("/Users/janinasoriano/Documents/School Work/Fall 2015/CS 1124/rec/rec01/rec01/jabberwocky.txt");
    //check if file is opened
    if(!ifschar)
    {
        cerr << "Couldn't open file" << endl;
        exit(3);
    }
    
    char character;
    int charCounter = 0;
    ifschar >> noskipws;
    
    //counts the characters
    while(ifschar >> character)
    {
        charCounter++;
        //cout << character << endl;
    }
    
    //close file
    ifschar.close();
    
    
    cout << endl;
    cout << "Number of lines: " << lineCounter << endl;
    cout << "Number of words: " << wordCounter << endl;
    cout << "Number of characters: " << charCounter << endl;
    
    
}
