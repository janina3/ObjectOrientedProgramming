//
//  hw01nfinal.cpp
//  hw
//
//  Created by Janina Soriano on 9/20/15.
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
void addWarrior(string name, int strength, vector<Warrior>& theWarriors);
void battle(Warrior& warrior1, Warrior& warrior2);
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


void battle(Warrior& warrior1, Warrior& warrior2)
{
//    int newWarriorStrength1 = 0;
//    int newWarriorStrength2 = 0;
    int strength1 = 0;
    int strength2 = 0;
    
    strength1 = warrior1.strength;
    strength2 = warrior2.strength;
    
    //display who is fighting
    cout << warrior1.name << " battles " << warrior2.name << endl;
    
    
    //print results
    
    
    //if warrior1 and warrior to have the same strength
    if (warrior1.strength == warrior2.strength)
    {
        cout << "Mutual Annihilation: " << warrior1.name << " and " << warrior2.name << " die at each other's hands." << endl;
        
//        strength1 = warrior1.strength;
//        strength2 = warrior2.strength;
        
        warrior1.strength = strength1 - strength2;
        
//        newWarriorStrength1 = warrior1.strength - warrior2.strength;
//        if(newWarriorStrength1 <= 0)
//        {
//            warrior1.strength = 0;
//        }
//        else
//        {
//            warrior1.strength = newWarriorStrength1;
//        }
        
        warrior2.strength = strength2 - strength1;
        
//        newWarriorStrength2 = warrior2.strength - warrior1.strength;
//        if(newWarriorStrength2 <= 0)
//        {
//            warrior2.strength = 0;
//        }
//        else
//        {
//            warrior2.strength = newWarriorStrength2;
//        }

    }
    
    //if warrior1 is stronger than warrior2
    else if (warrior1.strength > warrior2.strength)
    {
        cout << warrior1.name << " defeats " << warrior2.name << endl;
        
//        strength1 = warrior1.strength;
//        strength2 = warrior2.strength;
        
        warrior1.strength = strength1 - strength2;
        
//        newWarriorStrength1 = warrior1.strength - warrior2.strength;
//        if(newWarriorStrength1 <= 0)
//        {
//            warrior1.strength = 0;
//        }
//        else
//        {
//            warrior1.strength = newWarriorStrength1;
//        }
        
        warrior2.strength = strength2 - strength1;
        
//        newWarriorStrength2 = warrior2.strength - warrior1.strength;
//        if(newWarriorStrength2 <= 0)
//        {
//            warrior2.strength = 0;
//        }
//        else
//        {
//            warrior2.strength = newWarriorStrength2;
//        }
        
    }
    
    //if warrior2 is stronger than warrior1
    else
    {
        cout << warrior2.name << " defeats " << warrior1.name << endl;
        
//        strength1 = warrior1.strength;
//        strength2 = warrior2.strength;
        
        warrior1.strength = strength1 - strength2;
        
//        newWarriorStrength1 = warrior1.strength - warrior2.strength;
//        if(newWarriorStrength1 <= 0)
//        {
//            warrior1.strength = 0;
//        }
//        else
//        {
//            warrior1.strength = newWarriorStrength1;
//        }
        
        warrior2.strength = strength2 - strength1;
        
//        newWarriorStrength2 = warrior2.strength - warrior1.strength;
//        if(newWarriorStrength2 <= 0)
//        {
//            warrior2.strength = 0;
//        }
//        else
//        {
//            warrior2.strength = newWarriorStrength2;
//        }

    }
    
//    newWarriorStrength1 = warrior1.strength - warrior2.strength;
//    newWarriorStrength2 = warrior2.strength - warrior1.strength;
//    
//    warrior1.strength = newWarriorStrength1;
//    warrior2.strength = newWarriorStrength2;
//    
//    cout << "Warrior 1 Strength: " << warrior1.strength << endl;
//    cout << "Warrior 2 Strength: " << warrior2.strength << endl;

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
    
    //cout << "Name: " << theWarriors[1].name << " Strength: " << theWarriors[1].strength << endl;
    
}

void readFile(ifstream& newFile, vector<Warrior>& warriors)
{
    //    string warriorCall;
    //    string statusCall;
    //    string battleCall;
    string firstWord;
//    string name;
//    int strength;
//    string name1;
//    string name2;
//    Warrior warrior1;
//    Warrior warrior2;
    
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
            Warrior warrior1;
            Warrior warrior2;
            
            //cout << "Battle" << endl;
            newFile >> name1 >> name2;
            
            //cout << "Warrior 1: " << name1 << " and Warrior 2: " << name2 << endl;
            
            //cout << "Find Warrior 1: " << name1 << endl;
            
            for(size_t i = 0; i < warriors.size(); ++i)
            {
                //cout << "Current Warrior 1: " << warriors[i].name << endl;
                if(name1 == warriors[i].name)
                {
                    //cout << "Warrior 1: " << warriors[i].strength << endl;
                    warrior1 = warriors[i];
                    break;
                }
        
            }
            
            //cout << "Find Warrior 2: " << name2 << endl;
                
            for(size_t i = 0; i < warriors.size(); ++i)
            {
                //cout << "Current Warrior 2: " << warriors[i].name << endl;
                if(name2 == warriors[i].name)
                {
                    //cout << "Warrior 2: " << warriors[i].strength << endl;
                    warrior2 = warriors[i];
                    break;
                }
            }
            
            //cout << "Warrior 1: " << warrior1.name << " and Warrior 2: " << warrior2.name << endl;
            
            //cout << "Warrior 1: " << warrior1.strength << " and Warrior 2: " << warrior2.strength << endl;
            
            battle(warrior1, warrior2);
            
            for(size_t i = 0; i < warriors.size(); ++i)
            {
                if(name1 == warriors[i].name)
                {
                    warriors[i] = warrior1;
                    break;
                }
                
            }
            for(size_t i = 0; i < warriors.size(); ++i)
            {
                if(name2 == warriors[i].name)
                {
                    warrior2 = warriors[i];
                    break;
                }
                
            }
            
        
        }
    }
    
    newFile.close();
}