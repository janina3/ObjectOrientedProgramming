//
//  main.cpp
//  hw01
//
//  Created by Janina Soriano on 9/19/15.
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
public:
    string getName() const
    {
        return name;
    }
    
    int getStrength() const
    {
        return strength;
    }
    
    void setName(const string& theName)
    {
        name = theName;
    }
    
    void setStrength(int theStrength)
    {
        strength = theStrength;
    }

private:
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
        cout << "Status method" << endl;

        numWarriors += 1;
    }
    
    cout << "There are: " << numWarriors << " warriors" << endl;
    
    //display each warrior with strength
    
    Warrior tempWarrior;
    //can use same for loop as numWarriors but for readability reasons
    for (size_t i = 0; i < theWarriors.size(); ++i)
    {
        cout << "Warrior: " << tempWarrior.getName() << ", strength: " << tempWarrior.getStrength() << endl;
        
    }
    
    
}


void battle(Warrior& warrior1, Warrior& warrior2)
{
    //display who is fighting
    cout << warrior1.getName() << "battles" << warrior2.getName() << endl;
    
    
    //print results
    
    
    //if warrior1 and warrior to have the same strength
    if (warrior1.getStrength() == warrior2.getStrength())
    {
        cout << "Mutual Annihilation: " << warrior1.getName() << " and " << warrior2.getName() << " die at each other's hands." << endl;
    }
    
    //if warrior1 is stronger than warrior2
    else if (warrior1.getStrength() > warrior2.getStrength())
    {
        cout << warrior1.getName() << " defeats " << warrior2.getStrength() << endl;
    }
    
    //if warrior2 is stronger than warrior1
    else
    {
        cout << warrior2.getName() << " defeats " << warrior1.getName() << endl;
    }
    
    
}

void addWarrior(string name, int strength, vector<Warrior>& theWarriors)
{
    cout << "Name: " << name << " Strength: " << strength << endl;
    
    Warrior newWarrior;
    //save name to struct
    newWarrior.setName(name);
    
    //save strength to struct
    newWarrior.setStrength(strength);
    
    //add warrior to struct
    theWarriors.push_back(newWarrior);
    
    cout << "Name: " << theWarriors[1].getName() << " Strength: " << theWarriors[1].getStrength() << endl;
    
}

void readFile(ifstream& newFile, vector<Warrior>& warriors)
{
//    string warriorCall;
//    string statusCall;
//    string battleCall;
    string firstWord;
    string name;
    int strength;
    string name1;
    string name2;
    Warrior warrior1;
    Warrior warrior2;
    
    //detect the first word
    while(newFile >> firstWord)
    {
        if(firstWord == "Warrior")
        {
            cout << "Warrior" << endl;
            newFile >> name >> strength;
//            cout << "Name: " << name << " Strength: " << strength << endl;
            addWarrior(name, strength, warriors);
        }
        
        if(firstWord == "Status")
        {
            cout << "Status" << endl;
            status(warriors);
        }
        
        if(firstWord == "Battle")
        {
            cout << "Battle" << endl;
            newFile >> name1 >> name2;
            
            for(size_t i = warriors.size() - 1; i > 0; i++)
            {
                if(warriors[i].getName() == name1)
                {
                    warrior1 = warriors[i];
                }
                
                if(warriors[i].getName() == name2)
                {
                    warrior2 = warriors[i];
                }
            }
                        
            battle(warrior1, warrior2);
        }
    }
    
//    //create a vector of Warriors
//    while(newFile >> junk >> name >> strength)
//    {
//        addWarrior(name, strength, warriors);
//    }
//    
//    //if the input is 1 string, it is status
//    while(newFile >> junk)
//    {
//        cout << "test" << endl;
//        status(warriors);
//    }
//    
//    //if the input is 3 strings, it is battle
//    while(newFile >> junk >> name1 >> name2)
//    {
//        for(size_t i = warriors.size() - 1; i > 0; i++)
//        {
//            if(warriors[i].name == name1)
//            {
//                warrior1 = warriors[i];
//            }
//            
//            if(warriors[i].name == name2)
//            {
//                warrior2 = warriors[i];
//            }
//        }
//        
//        battle(warrior1, warrior2);
//    }
    
    
    newFile.close();
}
