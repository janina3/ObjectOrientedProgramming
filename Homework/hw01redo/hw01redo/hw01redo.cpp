//
//  hw01redo.cpp
//  hw01redo
//
//  Created by Janina Soriano on 10/2/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Warrior
{
    string name;
    int strength;
};


void openFile(ifstream& newFile);
void readFile(ifstream& newFile, vector<Warrior>& warriors);
void addWarrior(const string& name, int strength, vector<Warrior>& theWarriors);
void battle(vector<Warrior>& warriors, const string& name1, const string& name2);
void status(const vector<Warrior>& theWarriors);



int main()
{
    ifstream newFile;
    vector<Warrior> theWarriors;
    
    openFile(newFile);
    readFile(newFile, theWarriors);
    
}

void openFile(ifstream& newFile)
{
    //open warriors.txt
    newFile.open("//Users/janinasoriano/School Work/Fall 2015/CS 1124/Homework/hw01/hw01/warriors.txt");
    
    //check if file opened
    if(!newFile)
    {
        cerr << "Couldn't open file" << endl;
        exit(1);
    }
}

void status(const vector<Warrior>& theWarriors)
{
    //print num warriors
    int numWarriors = 0;
    
    //numWarriors = theWarriors.size();
    for (size_t i = 0; i < theWarriors.size(); ++i)
    {
        //cout << "Status method" << endl;
        numWarriors += 1;
    }
    
    cout << "There are: " << numWarriors << " warriors" << endl;
    
    //display each warrior with strength
    
    Warrior tempWarrior;
    //can use same for loop as numWarriors but for readability reasons
    for (size_t i = 0; i < theWarriors.size(); ++i)
    {
        tempWarrior = theWarriors[i];
        cout << "Warrior: " << tempWarrior.name << ", strength: " << tempWarrior.strength << endl;
        
    }
    
    
}


void battle(vector<Warrior>& warriors, const string& name1, const string& name2)
{
    //Find Warrior 1
    for(size_t i = 0; i < warriors.size(); ++i)
    {
        for(size_t j = 0; j < warriors.size(); ++j)
        {
            if(name1 == warriors[i].name && name2 == warriors[j].name)
            {
                int strength1 = 0;
                int strength2 = 0;
                
                strength1 = warriors[i].strength;
                strength2 = warriors[j].strength;

                //display who is fighting
                cout << warriors[i].name << " battles " << warriors[j].name << endl;
                
                cout << "Warrior 1: " << warriors[i].name << " " << warriors[i].strength << endl;
                cout << "Warrior 2: " << warriors[j].name << " " << warriors[j].strength << endl;
                
                
                //print results
                
                //if both warriors are already dead
                if(warriors[i].strength == 0 && warriors[j].strength == 0)
                {
                    cout << "Oh, NO! They're both dead! Yuck!" << endl;
                }
                
                //if warriors[i] and warrior to have the same strength
                else if(warriors[i].strength == warriors[j].strength)
                {
                    cout << "Mutual Annihilation: " << warriors[i].name << " and " << warriors[j].name << " die at each other's hands." << endl;
                    
                    warriors[i].strength = strength1 - strength2;
                    warriors[j].strength = strength2 - strength1;
                    
                }
                
                //if warrior 1 is already dead
                else if(warriors[i].strength == 0)
                {
                    cout << "He's dead, " << warriors[j].name << endl;
                }
                
                //if warrior 2 is already dead
                else if(warriors[j].strength == 0)
                {
                    cout << "He's dead, " << warriors[i].name << endl;
                }
                
                //if warriors[i] is stronger than warriors[j]
                else if(warriors[i].strength > warriors[j].strength)
                {
                    cout << warriors[i].name << " defeats " << warriors[j].name << endl;
                    
                    warriors[i].strength = strength1 - strength2;
                    warriors[j].strength = 0;
                    
                }
                
                //if warriors[j] is stronger than warriors[i]
                else
                {
                    cout << warriors[j].name << " defeats " << warriors[i].name << endl;
                    
                    warriors[i].strength = 0;
                    
                    warriors[j].strength = strength2 - strength1;
                    
                }
                
                cout << "Warrior 1: " << warriors[i].name << " " << warriors[i].strength << endl;
                cout << "Warrior 2: " << warriors[j].name << " " << warriors[j].strength << endl;

                
            }
        
        }
        
    }
    
}

void addWarrior(const string& name, int strength, vector<Warrior>& theWarriors)
{
    //cout << "Name: " << name << " Strength: " << strength << endl;
    
    Warrior newWarrior;
    //save name to struct
    newWarrior.name = name;
    
    //save strength to struct
    newWarrior.strength = strength;
    
    //add warrior to struct
    theWarriors.push_back(newWarrior);

    
}

void readFile(ifstream& newFile, vector<Warrior>& warriors)
{
    string firstWord;
    
    //detect the first word
    while(newFile >> firstWord)
    {
        if(firstWord == "Warrior")
        {
            string name;
            int strength;
            //cout << "Warrior" << endl;
            newFile >> name >> strength;
            //            cout << "Name: " << name << " Strength: " << strength << endl;
            addWarrior(name, strength, warriors);
        }
        
        if(firstWord == "Status")
        {
            //cout << "Status" << endl;
            status(warriors);
        }
        
        if(firstWord == "Battle")
        {
            string name1;
            string name2;
//            Warrior warrior1;
//            Warrior warrior2;
            
            //cout << "Battle" << endl;
            newFile >> name1 >> name2;
            battle(warriors, name1, name2);
            
//            for(size_t i = 0; i < warriors.size(); ++i)
//            {
//                if(name1 == warriors[i].name)
//                {
//                    warriors[i] = warrior1;
//                    break;
//                }
//                
//            }
//            for(size_t i = 0; i < warriors.size(); ++i)
//            {
//                if(name2 == warriors[i].name)
//                {
//                    warrior2 = warriors[i];
//                    break;
//                }
//                
//            }
            
            
        }
    }
    
    newFile.close();
}