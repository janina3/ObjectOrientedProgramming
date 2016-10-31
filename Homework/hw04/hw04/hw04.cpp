//
//  hw04.cpp
//  hw04
//
//  CS1124
//  N14209086
//
//  Created by Janina Soriano on 10/9/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Warrior
{
public:
    Warrior(const string& theName, double theStrength) : name(theName), strength(theStrength) {}
    
    //Accesors
    string getName() const
    {
        return name;
    }
    
    double getStrength() const
    {
        return strength;
    }
    
    //Modifiers
    void setName(string& newName)
    {
        name = newName;
    }
    
    void setStrength(double newStrength)
    {
        strength = newStrength;
    }
    
    
private:
    string name;
    double strength;
};

class Noble
{
public:
    Noble(const string& theName) : name(theName) {}
    
    string getName() const
    {
        return name;
    }
    
    void hire(Warrior*& newWarrior)
    {
        army.push_back(newWarrior);
    }
    
    void display() const
    {
        cout << name << " has an army of " << army.size() << endl;
        for(size_t i = 0; i < army.size(); i ++)
        {
            cout << "       " << army[i]->getName() << ": " << army[i]->getStrength() << endl;
        }
    }
    
    void fire(Warrior*& firedWarrior)
    {
        cout << firedWarrior->getName() << ", you're fired! -- " << name << endl;
        
        for(size_t i = 0; i < army.size(); ++i)
        {
            if(army[i] == firedWarrior)
            {
                for(size_t j = i; j < army.size() - 1; ++j)
                {
                    army[j] = army[j + 1];
                }
            }
        }
        
        army.pop_back();
    }
    
    void battle(Noble*& otherNoble)
    {
        double army1Total = 0;
        double army2Total = 0;
        
        cout << name << " battles " << otherNoble->name << endl;
        
        //add the strength of all the warriors in the first Noble's army
        for(Warrior*& warrior : army)
        {
            army1Total = army1Total + warrior->getStrength();
        }
        
        //add the strength of all the warriors in the second Noble's army
        for(Warrior*& warrior : otherNoble->army)
        {
            army2Total = army2Total + warrior->getStrength();
        }
        
        //if both armies are already dead
        if(army1Total == 0 && army2Total == 0)
        {
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        
        //if army1 is already dead
        else if(army1Total == 0)
        {
            cout << "He's dead, " << otherNoble->name << endl;
        }
        
        //if army2 is already dead
        else if(army2Total == 0)
        {
            cout << "He's dead, " << name << endl;
        }
        
        //if both armies have the same strength, all warriors in the army have a new strength of 0
        else if(army1Total == army2Total)
        {
            cout << "Mutual Annihilation: " << name << " and " << otherNoble->name << " die at each other's hands" << endl;
            
            for(Warrior*& warrior : army)
            {
                warrior->setStrength(0);
            }
            
            for(Warrior*& warrior : otherNoble->army)
            {
                warrior->setStrength(0);
            }
            
        }
        
        //if army1 has a higher strength, multiply the strength of all the warriors in army1 with the ratio, and set all the warriors in army2 with a new strength of 0
        else if(army1Total > army2Total)
        {
            cout << name << " defeats " << otherNoble->name << endl;
            
            double armyRatio = army2Total / army1Total;
            
            if(army.size() == 1)
            {
                for(Warrior*& warrior : army)
                {
                    warrior->setStrength(army1Total - army2Total);
                }
            }
            else
            {
                
                for(Warrior*& warrior : army)
                {
                    warrior->setStrength(warrior->getStrength() * armyRatio);
                }
            }
            
            for (Warrior*& warrior : otherNoble->army)
            {
                warrior->setStrength(0);
            }
        }
        
        //if army2 has a higher strength, multiply the strength of all the warriors in army2 with the ratio, and set all the warriors in army1 with a new strength of 0
        else
        {
            cout << otherNoble->name << " defeats " << name << endl;
            
            double armyRatio = army1Total / army2Total;
            
            for(Warrior*& warrior : army)
            {
                warrior->setStrength(0);
            }
            
            if(otherNoble->army.size() == 1)
            {
                for(Warrior*& warrior : otherNoble->army)
                {
                    warrior->setStrength(army2Total - army1Total);
                }
            }
            else
            {
                
                for(Warrior*& warrior : otherNoble->army)
                {
                    warrior->setStrength(warrior->getStrength() * armyRatio);
                }
            }
            
        }
        
    }
    
private:
    string name;
    vector<Warrior*> army;
};

void openFile(ifstream& newFile);
void readFile(ifstream& newFile, vector<Warrior*>& unemployedWarriors, vector<Warrior*>& employedWarriors, vector<Noble*>& nobles);
void status(const vector<Warrior*>& unemployedWarriors, const vector<Warrior*>& employedWarriors, const vector<Noble*>& nobles);
size_t checkNoble(const string& nobleName, const vector<Noble*> nobles);
size_t checkWarrior(const string& warriorName, const vector<Warrior*>& warriors);

int main()
{
    ifstream newFile;
    vector<Warrior*> unemployedWarriors;
    vector<Warrior*> employedWarriors;
    vector<Noble*> theNobles;
    
    openFile(newFile);
    readFile(newFile, unemployedWarriors, employedWarriors, theNobles);
    
}

void openFile(ifstream& newFile)
{
    //open nobleWarriors.txt
    newFile.open("/Users/janinasoriano/School Work/Fall 2015/CS 1124/Homework/hw04/nobleWarriors.txt");
    
    //check if file opened
    if(!newFile)
    {
        cerr << "Couldn't open file" << endl;
        exit(1);
    }
}

void status(const vector<Warrior*>& unemployedWarriors, const vector<Warrior*>& employedWarriors, const vector<Noble*>& nobles)
{
    cout << "Nobles: " << endl;
    for(Noble* noble : nobles)
    {
        noble->display();
    }
    if(nobles.size() == 0)
    {
        cout << "NONE" << endl;
    }
    
    cout << "Unemployed Warriors: " << endl;
    for(Warrior* warrior : unemployedWarriors)
    {
        cout << warrior->getName() << ": " << warrior->getStrength() << endl;
    }
    if(unemployedWarriors.size() == 0)
    {
        cout << "NONE" << endl;
    }
    
    
    
}

void readFile(ifstream& newFile, vector<Warrior*>& unemployedWarriors, vector<Warrior*>& employedWarriors, vector<Noble*>& nobles)
{
    string firstWord;
    
    //detect the first word
    while(newFile >> firstWord)
    {
        if(firstWord == "Noble")
        {
            string name;
            newFile >> name;
            
            //check if a noble with the same name already exists
            for(Noble* noble : nobles)
            {
                if(noble->getName() == name)
                {
                    cerr << "Error. Noble already exists." << endl;
                    exit(-1);
                }
            }
            
            Noble* noblePtr = new Noble(name);
            nobles.push_back(noblePtr);
        }
        
        if(firstWord == "Warrior")
        {
            string name;
            int strength;
            newFile >> name >> strength;
            
            //check if a warrior with the same name already exists
            for(Warrior* warrior : unemployedWarriors)
            {
                if(warrior->getName() == name)
                {
                    cerr << "Error. Warrior already exists." << endl;
                    exit(-1);
                }
                else
                {
                    for(Warrior* eWarrior : employedWarriors)
                    {
                        if(eWarrior->getName() == name)
                        {
                            cerr << "Error with create warrior. Warrior already exists." << endl;
                            exit(-1);
                        }
                        else
                        {
                            Warrior* warriorPtr = new Warrior(name, strength);
                            unemployedWarriors.push_back(warriorPtr);
                        }
                    }
                }
            }
            
            Warrior* warriorPtr = new Warrior(name, strength);
            unemployedWarriors.push_back(warriorPtr);
        }
        
        if(firstWord == "Hire")
        {
            string nobleName;
            string warriorName;
            size_t nobleIndex;
            size_t warriorIndex;
            
            newFile >> nobleName >> warriorName;
            
            //check that the noble exists
            nobleIndex = checkNoble(nobleName, nobles);
            
            //check that warrior is employed
            for(Warrior*& warrior : employedWarriors)
            {
                    if(warrior->getName() == warriorName)
                    {
                        cout << "Error with hire. Warrior is already in an army." << endl;
                        exit(-1);
                    }
            }
                    
            //if unemployed
            warriorIndex = checkWarrior(warriorName, unemployedWarriors);
            
            employedWarriors.push_back(unemployedWarriors[warriorIndex]);
            
            nobles[nobleIndex]->hire(unemployedWarriors[warriorIndex]);
            
            for(size_t j = warriorIndex; j < unemployedWarriors.size(); j++)
            {
                unemployedWarriors[j] = unemployedWarriors[j + 1];
            }
            
            unemployedWarriors.pop_back();
            
        }
        
        if(firstWord == "Fire")
        {
            string nobleName;
            string warriorName;
            size_t nobleIndex;
            size_t warriorIndex;
            
            newFile >> nobleName >> warriorName;
            
            //check that the noble exists
            nobleIndex = checkNoble(nobleName, nobles);
            
            //check that warrior exists
            warriorIndex = checkWarrior(warriorName, employedWarriors);
            
            unemployedWarriors.push_back(employedWarriors[warriorIndex]);
            
            nobles[nobleIndex]->fire(employedWarriors[warriorIndex]);
    
            for(size_t j = warriorIndex; j < employedWarriors.size() - 1; j++)
            {
                employedWarriors[j] = employedWarriors[j + 1];
            }
                        
            employedWarriors.pop_back();
        }
        
        if(firstWord == "Status")
        {
            cout << "Status" << endl;
            cout << "======" << endl;
            status(unemployedWarriors, employedWarriors, nobles);
        }
        
        if(firstWord == "Battle")
        {
            string noble1;
            string noble2;
            size_t noble1Index;
            size_t noble2Index;
            
            newFile >> noble1 >> noble2;
            
            //check that the noble1 exists
            noble1Index = checkNoble(noble1, nobles);
            
            //check that noble2 exists
            noble2Index = checkNoble(noble2, nobles);
            
            nobles[noble1Index]->battle(nobles[noble2Index]);
        }
        
        if(firstWord == "Clear")
        {
            for(Noble*& noble : nobles)
            {
                delete noble;
                noble = nullptr;
            }
            nobles.clear();
            
            for(Warrior*& warrior : unemployedWarriors)
            {
                delete warrior;
                warrior = nullptr;
            }
            unemployedWarriors.clear();
            
            for(Warrior* eWarrior : employedWarriors)
            {
                delete eWarrior;
                eWarrior = nullptr;
            }
            employedWarriors.clear();
        }
    }
    
    newFile.close();
}

size_t checkNoble(const string& nobleName, const vector<Noble*> nobles)
{
    for(size_t i = 0; i < nobles.size(); i++)
    {
        if(nobles[i]->getName() == nobleName)
        {
            return i;
        }
    }
    
    cerr << "Error. Noble does not exist." << endl;
    exit(-1);

}

size_t checkWarrior(const string& warriorName, const vector<Warrior*>& warriors)
{
    for(size_t i = 0; i < warriors.size(); i++)
    {
        if(warriors[i]->getName() == warriorName)
        {
            return i;
        }
    }
    
    cerr << "Error" << endl;
    exit(-1);
}

