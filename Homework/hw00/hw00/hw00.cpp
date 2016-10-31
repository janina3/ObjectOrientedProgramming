//
//  hw00.cpp
//  hw00
//
//  Created by Janina Soriano on 9/11/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


void openFile(ifstream& newFile);
void readFile(ifstream& newFile, vector<string>& encrypted, int steps);
void changeString(string& encrypted, int& steps);
char decrypt(char letter, int steps);
void printReverseVector(vector<string>& encrypted);




int main()
{
    ifstream newFile;
    vector<string> encrypted;
    int steps = 0;
    
    openFile(newFile);
    readFile(newFile, encrypted, steps);
    printReverseVector(encrypted);
    
    return 0;
    
    
}

void openFile(ifstream& newFile)
{
    //open file
    newFile.open("/Users/janinasoriano/Documents/School Work/Fall 2015/CS 1124/Homework/hw00/hw00/encrypted.txt");
    
    //check if file opened
    if(!newFile)
    {
        cerr << "Couldn't open file" << endl;
        exit(1);
    }
}

void readFile(ifstream& newFile, vector<string>& encrypted, int steps)
{
    //get the rotation number for the encryption
    newFile >> steps;
    string newLine;
    
    //extracts characters from newFile into newLine until the new line character
    while(getline(newFile, newLine))
    {
        changeString(newLine, steps);
        encrypted.push_back(newLine);
        
    }
    
    newFile.close();
}

void changeString(string& newLine, int& steps)    //goes through each character in a string and decrypts it
{
    for(char& letter : newLine)
    {
        letter = decrypt(letter, steps);
    }
}

char decrypt(char letter, int steps)    //changes one character at a time depending on the given number of steps
{
    char newLetter;
    int newSteps;
    
    if(letter >= 'a' && letter <= 'z')  //check if the letter is a letter
    {
        if(letter - steps < 'a')    //if the number of steps before the given letter falls out of the 26 lowercase letters
        {
            newSteps = 26 - steps;
            newLetter = letter + newSteps;
        }
        else
        {
            newLetter = letter - steps;
        }
    }
    else
    {
        return letter;
    }
    
    return newLetter;
}

void printReverseVector(vector<string>& encrypted)  //reverses the order of the lines in a given vector
{
    for (size_t i = encrypted.size()-1; i > 0; i--)
    {
        cout << encrypted[i] << endl;
    }
    cout << encrypted[0] << endl;
}





