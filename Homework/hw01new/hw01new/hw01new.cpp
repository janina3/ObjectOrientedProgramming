//
//  hw01new.cpp
//  hw
//
//  Created by Janina Soriano on 9/21/15.
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

void addWarrior(string name, int strength, vector<Warrior> theWarriors)
{
    Warrior newWarrior;
    //save name to struct
    newWarrior.name = name;
    
    //save strength to struct
    newWarrior.strength = strength;
    
    //add warrior to struct
    theWarriors.push_back(newWarrior);
    
}

void battle(Warrior warrior1, Warrior warrior2)
{
    //display who is fighting
    cout << warrior1.name << "battles" << warrior2.name << endl;
    
    
    //print results
    
    
    //if warrior1 and warrior to have the same strength
    if (warrior1.strength == warrior2.strength)
    {
        cout << "Mutual Annihilation: " << warrior1.name << " and " << warrior2.name << " die at each other's hands." << endl;
    }
    
    //if warrior1 is stronger than warrior2
    else if (warrior1.strength > warrior2.strength)
    {
        cout << warrior1.name << " defeats " << warrior2.name << endl;
    }
    
    //if warrior2 is stronger than warrior1
    else
    {
        cout << warrior2.name << " defeats " << warrior1.name << endl;
    }
    
    
}

void status(vector<Warrior> theWarriors)
{
    //print num warriors
    int numWarriors = 0;
    //numWarriors = theWarriors.size();
    for (size_t i = theWarriors.size() - 1; i > 0; i ++)
    {
        numWarriors += 1;
    }
    
    cout << "There are: " << numWarriors << "warriors" << endl;
    
    //display each warrior with strength
    
    Warrior tempWarrior;
    //can use same for loop as numWarriors but for readability reasons
    for (size_t i = theWarriors.size() - 1; i > 0; i++)
    {
        cout << "Warrior: " << tempWarrior.name << ", strength: " << tempWarrior.strength << endl;
        
    }
    
    
}

int main()
{
    //open warriors.txt
    ifstream ifs("/Users/janinasoriano/School Work/Fall 2015/CS 1124/Homework/hw01new/warriors.txt");
    if(!ifs)
    {
        cerr << "File did not open" << endl;
        exit(1);
    }
    
    vector<Warrior> theWarriors;
    string name;
    int strength;
    string statusCall;
    string battleCall;
    string name1;
    string name2;
    Warrior warrior1;
    Warrior warrior2;
    
    //create a vector of Warriors
    while (ifs >> name >> strength)
    {
        addWarrior(name, strength, theWarriors);
    }
    
    //if the input is 1 string, it is status
    while (ifs >> statusCall)
    {
        status(theWarriors);
    }
    
    //if the input is 3 strings, it is battle
    while (ifs >> battleCall >> name1 >> name2)
    {
        for (size_t i = theWarriors.size() - 1; i > 0; i++)
        {
            if(theWarriors[i].name == name1)
            {
                warrior1 = theWarriors[i];
            }
            
            if(theWarriors[i].name == name2)
            {
                warrior2 = theWarriors[i];
            }
        }
        
        battle(warrior1, warrior2);
    }
    
    
    ifs.close();
    
    return 0;
}

