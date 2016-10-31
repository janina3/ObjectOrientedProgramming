//
//  main.cpp
//  hw02
//
//  Created by Janina Soriano on 10/2/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//  CS1124
//  N14209086
//

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Weapon
{
public:
    Weapon(const string& theName, int theStrength) : name(theName), strength(theStrength) {}
    
    //Accessors
    string getName() const
    {
        return name;
    }
    
    int getStrength() const
    {
        return strength;
    }
    
    
    //Modifiers
    void setName(string& newName)
    {
       name = newName;
    }
    
    void setStrength(int newStrength)
    {
        strength = newStrength;
    }
    
private:
    string name;
    int strength;
};

class Warrior
{
public:
    Warrior(const string& theName, const string& weaponName, int strength) : name(theName), weapon(weaponName, strength) {}
    
    //Accesors
    string getName() const
    {
        return name;
    }
    
    int getWeaponStrength() const
    {
        return weapon.getStrength();
    }
    
    //Modifiers
    void setName(string& newName)
    {
        name = newName;
    }
    
    void setWeaponStrength(int newStrength)
    {
        weapon.setStrength(newStrength);
    }
    
    
private:
    string name;
    Weapon weapon;
};

void openFile(ifstream& newFile);
void readFile(ifstream& newFile, vector<Warrior>& warriors);
void addWarrior(const string& name, const string& weaponName, int strength, vector<Warrior>& theWarriors)
;
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
    newFile.open("/Users/janinasoriano/School Work/Fall 2015/CS 1124/Homework/hw02/warriors.txt");
    
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
    //can use same for loop as numWarriors but for readability reasons
    for (size_t i = 0; i < theWarriors.size(); ++i)
    {
        cout << "Warrior: " << theWarriors[i].getName() << ", strength: " << theWarriors[i].getWeaponStrength() << endl;
        
    }
    
    
}


void battle(vector<Warrior>& warriors, const string& name1, const string& name2)
{
    //Find Warrior 1
    for(size_t i = 0; i < warriors.size(); ++i)
    {
        for(size_t j = 0; j < warriors.size(); ++j)
        {
            if(name1 == warriors[i].getName() && name2 == warriors[j].getName())
            {
                int strength1 = 0;
                int strength2 = 0;
                
                strength1 = warriors[i].getWeaponStrength();
                strength2 = warriors[j].getWeaponStrength();
                
                //display who is fighting
                cout << warriors[i].getName() << " battles " << warriors[j].getName() << endl;
                
                cout << "Warrior 1: " << warriors[i].getName() << " " << warriors[i].getWeaponStrength() << endl;
                cout << "Warrior 2: " << warriors[j].getName() << " " << warriors[j].getWeaponStrength() << endl;
                
                
                //print results
                
                //if both warriors are already dead
                if(warriors[i].getWeaponStrength() == 0 && warriors[j].getWeaponStrength() == 0)
                {
                    cout << "Oh, NO! They're both dead! Yuck!" << endl;
                }
                
                //if warriors[i] and warrior to have the same strength
                else if(warriors[i].getWeaponStrength() == warriors[j].getWeaponStrength())
                {
                    cout << "Mutual Annihilation: " << warriors[i].getName() << " and " << warriors[j].getName() << " die at each other's hands." << endl;
                    
                    warriors[i].setWeaponStrength(strength1 - strength2);
                    warriors[j].setWeaponStrength(strength1 - strength2);
                    
                }
                
                //if warriors[i] is already dead
                else if(warriors[i].getWeaponStrength() == 0)
                {
                    cout << "He's dead, " << warriors[j].getName() << endl;
                }
                
                //if warriors[j] is already dead
                else if(warriors[j].getWeaponStrength() == 0)
                {
                    cout << "He's dead, " << warriors[i].getName() << endl;
                }
                
                //if warriors[i] is stronger than warriors[j]
                else if(warriors[i].getWeaponStrength() > warriors[j].getWeaponStrength())
                {
                    cout << warriors[i].getName() << " defeats " << warriors[j].getName() << endl;
                    
                    warriors[i].setWeaponStrength(strength1 - strength2);
                    warriors[j].setWeaponStrength(0);
                    
                }
                
                //if warriors[j] is stronger than warriors[i]
                else
                {
                    cout << warriors[j].getName() << " defeats " << warriors[i].getName() << endl;
                    
                    warriors[i].setWeaponStrength(0);
                    
                    warriors[j].setWeaponStrength(strength2 - strength1);
                    
                }
                
                cout << "Warrior 1: " << warriors[i].getName() << " " << warriors[i].getWeaponStrength() << endl;
                cout << "Warrior 2: " << warriors[j].getName() << " " << warriors[j].getWeaponStrength() << endl;
                
                
            }
            
        }
        
    }
    
}

void addWarrior(const string& name, const string& weaponName, int strength, vector<Warrior>& theWarriors)
{
    Warrior newWarrior(name, weaponName, strength);
    
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
            string weaponName;
            int strength;
            newFile >> name >> weaponName >> strength;
            addWarrior(name, weaponName, strength, warriors);
        }
        
        if(firstWord == "Status")
        {
            status(warriors);
        }
        
        if(firstWord == "Battle")
        {
            string name1;
            string name2;
          
            newFile >> name1 >> name2;
            battle(warriors, name1, name2);
            
        }
    }
    
    newFile.close();
}