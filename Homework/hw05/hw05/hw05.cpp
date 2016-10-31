//
//  hw05.cpp
//  hw05
//
//  CS1124
//  N14209086
//
//  Created by Janina Soriano on 10/29/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Protector;

class Noble
{
    
public:
    Noble(const string& theName, double theStrength) : name(theName), strength(theStrength), alive(true)  {}
    
    //Accessors
    string getName() const
    {
        return name;
    }
    
    bool isAlive() const
    {
        return alive;
    }
    
    virtual double getStrength() const = 0;
    
    //Modifiers
    void setLife(bool life)
    {
        alive = life;
    }
    void setName(string& newName)
    {
        name = newName;
    }
    
    virtual void setStrength(double newStrength) = 0;
    
    //Other Methods
    
    /*
    void display() const
    {
        cout << name << " has an army of " << army.size() << endl;
        for(size_t i = 0; i < army.size(); i ++)
        {
            cout << "       " << army[i]->getName() << ": " << army[i]->getStrength() << endl;
        }
    }
    */
    
    virtual void battleCries() const = 0;
    virtual void fire(Protector& fProtector) = 0;
    
    void battle(Noble& oNoble)
    {
        Noble* otherNoble = &oNoble;
        
        cout << name << " battles " << otherNoble->name << endl;
//        cout << getStrength() << " battles " << otherNoble->getStrength() << endl;
        
        //if both armies are already dead
        if(!alive && !(otherNoble->alive))
        {
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        
        //if army1 is already dead
        else if(!alive)
        {
            cout << "He's dead, " << otherNoble->name << endl;
        }
        
        //if army2 is already dead
        else if(!(otherNoble->alive))
        {
            cout << "He's dead, " << name << endl;
        }
        
        //if both armies have the same strength, all Protectors in the army have a new strength of 0
        else if(getStrength() == otherNoble->getStrength())
        {
            battleCries();
            otherNoble->battleCries();
            
            cout << "Mutual Annihilation: " << name << " and " << otherNoble->name << " die at each other's hands" << endl;
            
            setStrength(0);
            alive = false;
            
            otherNoble->setStrength(0);
            otherNoble->alive = false;
        }
        
        //if army1 has a higher strength, multiply the strength of all the Protectors in army1 with the ratio, and set all the Protectors in army2 with a new strength of 0
        else if(getStrength() > otherNoble->getStrength())
        {
            battleCries();
            otherNoble->battleCries();
            
            cout << name << " defeats " << otherNoble->name << endl;
            
            double ratio = otherNoble->getStrength() / getStrength();
            
            setStrength(ratio);
            
            otherNoble->setStrength(0);
            otherNoble->alive = false;
        }
        
        //if army2 has a higher strength, multiply the strength of all the Protectors in army2 with the ratio, and set all the Protectors in army1 with a new strength of 0
        else
        {
            battleCries();
            otherNoble->battleCries();
            
            cout << otherNoble->name << " defeats " << name << endl;
            
            double ratio = getStrength() / otherNoble->getStrength();
            
            setStrength(0);
            alive = false;
            
            otherNoble->setStrength(ratio);
        }
        
    }
    
protected:
    string name;
    bool alive;
    double strength;
};

class Protector
{
public:
    Protector(const string& theName, double theStrength) : name(theName), strength(theStrength), alive(true), employed(false), leader(nullptr) {}
    
    //Accesors
    string getName() const
    {
        return name;
    }
    
    double getStrength() const
    {
        return strength;
    }
    
    bool isAlive() const
    {
        return alive;
    }
    
    bool isEmployed() const
    {
        return employed;
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
    
    void setEmploy(bool newEmploy)
    {
        employed = newEmploy;
    }
    
    void setLife(bool life)
    {
        alive = life;
    }
    
    void setLeader(Noble* newLeader)
    {
        leader = newLeader;
    }
    
    //Other methods
    void fired()
    {
        leader->fire(*this);
        leader = nullptr;
    }
    
    virtual void defend() const = 0;
    
protected:
    string name;
    double strength;
    bool employed;
    bool alive;
    Noble* leader;
};

class Lord : public Noble
{
public:
    Lord(const string& theName) : Noble(theName, 0)  {}
    
    //Modifiers
    void setStrength(double ratio)   //deal with army size later
    {
        for(size_t i = 0; i < army.size(); i++)
        {
            army[i]->setStrength(army[i]->getStrength() * ratio);
        }
    }
    
    //Accessors
    double getStrength() const override
    {
        double armyStrength = 0;
        
        for(size_t i = 0; i < army.size(); i++)
        {
            armyStrength = armyStrength + army[i]->getStrength();
//            cout << "Get Strength: " << armyStrength << endl;
        }
        
        return armyStrength;
    }
    
    //Other Methods
    void hires(Protector& nProtector)
    {
        Protector* newProtector = &nProtector;
        
        if(newProtector->isAlive() == true && alive == true)
        {
            if(newProtector->isEmployed() == true)
            {
                newProtector->fired();
                newProtector->setEmploy(false);
            }
            
            army.push_back(newProtector);
            newProtector->setEmploy(true);
            newProtector->setLeader(this);
        }
    }
    
    void fire(Protector& fProtector)
    {
        Protector* firedProtector = &fProtector;
        
//        cout << firedProtector->getName() << ", you're fired! -- " << name << endl;
        
        for(size_t i = 0; i < army.size(); ++i)
        {
            if(army[i] == firedProtector)
            {
                for(size_t j = i; j < army.size() - 1; ++j)
                {
                    army[j] = army[j + 1];
                }
            }
        }
        
        army.pop_back();
        
        firedProtector->setEmploy(false);
    }
    
    void battleCries() const override
    {
        for(size_t i = 0; i < army.size(); i++)
        {
            army[i]->defend();
        }
    }
    
private:
    vector<Protector*> army;
//    double strength = getStrength();    //personal strength is technically army strength...
};


class PersonWithStrengthToFight : public Noble
{
public:
    PersonWithStrengthToFight(const string& theName, double theStrength) : Noble(theName, theStrength) {}
    
    //Modifiers
    void setStrength(double newStrength) override
    {
        strength = newStrength;
    }
    
    //Accessors
    double getStrength() const override
    {
        return strength;
    }
    
    //Other methods
    void battleCries() const override
    {
        //no army, no battle cries
        //Protectors are lowly and don't know guerilla warfare like PersonWithStrengthToFight does
    }
    
    void fire(Protector& fProtector) override
    {
        //no army, no fire
    }
};


class Wizard : public Protector
{
public:
    Wizard(const string& theName, double theStrength) : Protector(theName, theStrength) {}
    
    //Other methods
    void defend() const override
    {
        if(alive == true)
        {
            cout << "POOF!" << endl;
        }
    }
};


class Warrior : public Protector
{
public:
    Warrior(const string& theName, double theStrength) : Protector(theName, theStrength) {}
    
    virtual void defend() const = 0;
};

class Archer : public Warrior
{
public:
    Archer(const string& theName, double theStrength) : Warrior(theName, theStrength) {}
    
    void defend() const override
    {
        if(alive == true)
        {
            cout << "TWANG! " << name << "says: Take that in the name of my lord, " << leader->getName() << endl;
        }
    }
};

class Swordsman : public Warrior
{
public:
    Swordsman(const string& theName, double theStrength) : Warrior(theName, theStrength) {}
    
    void defend() const override
    {
        if(alive == true)
        {
            cout << "CLANG! " << name << "says: Take that in the name of my lord, " << leader->getName() << endl;
        }
    }
};


/*
void openFile(ifstream& newFile);
void readFile(ifstream& newFile, vector<Protector*>& unemployedProtectors, vector<Protector*>& employedProtectors, vector<Noble*>& nobles);
void status(const vector<Protector*>& unemployedProtectors, const vector<Protector*>& employedProtectors, const vector<Noble*>& nobles);
*/

size_t checkNoble(const string& nobleName, const vector<Noble*> nobles);
size_t checkProtector(const string& ProtectorName, const vector<Protector*>& Protectors);

int main() {
    Lord sam("Sam");
    Archer samantha("Samantha", 200);
    sam.hires(samantha);
    Lord joe("Joe");
    PersonWithStrengthToFight randy("Randolf the Elder", 250);
    joe.battle(randy);
    joe.battle(sam);
    Lord janet("Janet");
    Swordsman hardy("TuckTuckTheHardy", 100);
    Swordsman stout("TuckTuckTheStout", 80);
    janet.hires(hardy);
    janet.hires(stout);
    PersonWithStrengthToFight barclay("Barclay the Bold", 300);
    janet.battle(barclay);
    janet.hires(samantha);
    Archer pethora("Pethora", 50);
    Archer thora("Thorapleth", 60);
    Wizard merlin("Merlin", 150);
    janet.hires(pethora);
    janet.hires(thora);
    sam.hires(merlin);
    janet.battle(barclay);
    sam.battle(barclay);
    joe.battle(barclay);
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

size_t checkProtector(const string& ProtectorName, const vector<Protector*>& Protectors)
{
    for(size_t i = 0; i < Protectors.size(); i++)
    {
        if(Protectors[i]->getName() == ProtectorName)
        {
            return i;
        }
    }
    
    cerr << "Error" << endl;
    exit(-1);
}

/*
void openFile(ifstream& newFile)
{
    //open nobleProtectors.txt
    newFile.open("/Users/janinasoriano/School Work/Fall 2015/CS 1124/Homework/hw04/nobleProtectors.txt");
    
    //check if file opened
    if(!newFile)
    {
        cerr << "Couldn't open file" << endl;
        exit(1);
    }
}
 

void status(const vector<Protector*>& unemployedProtectors, const vector<Protector*>& employedProtectors, const vector<Noble*>& nobles)
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
    
    cout << "Unemployed Protectors: " << endl;
    for(Protector* Protector : unemployedProtectors)
    {
        cout << Protector->getName() << ": " << Protector->getStrength() << endl;
    }
    if(unemployedProtectors.size() == 0)
    {
        cout << "NONE" << endl;
    }
    
    
    
}

void readFile(ifstream& newFile, vector<Protector*>& unemployedProtectors, vector<Protector*>& employedProtectors, vector<Noble*>& nobles)
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
        
        if(firstWord == "Protector")
        {
            string name;
            double strength;
            newFile >> name >> strength;
            
            //check if a Protector with the same name already exists
            for(Protector* Protector : unemployedProtectors)
            {
                if(Protector->getName() == name)
                {
                    cerr << "Error. Protector already exists." << endl;
                    exit(-1);
                }
                else
                {
                    for(Protector* eProtector : employedProtectors)
                    {
                        if(eProtector->getName() == name)
                        {
                            cerr << "Error with create Protector. Protector already exists." << endl;
                            exit(-1);
                        }
                        else
                        {
                            Protector* ProtectorPtr = new Protector(name, strength);
                            unemployedProtectors.push_back(ProtectorPtr);
                        }
                    }
                }
            }
            
            Protector* ProtectorPtr = new Protector(name, strength);
            unemployedProtectors.push_back(ProtectorPtr);
        }
        
        if(firstWord == "Hire")
        {
            string nobleName;
            string ProtectorName;
            size_t nobleIndex;
            size_t ProtectorIndex;
            
            newFile >> nobleName >> ProtectorName;
            
            //check that the noble exists
            nobleIndex = checkNoble(nobleName, nobles);
            
            //check that Protector is employed
            for(Protector*& Protector : employedProtectors)
            {
                if(Protector->getName() == ProtectorName)
                {
                    cout << "Error with hire. Protector is already in an army." << endl;
                    exit(-1);
                }
            }
            
            //if unemployed
            ProtectorIndex = checkProtector(ProtectorName, unemployedProtectors);
            
            employedProtectors.push_back(unemployedProtectors[ProtectorIndex]);
            
            nobles[nobleIndex]->hires(unemployedProtectors[ProtectorIndex]);
            
            for(size_t j = ProtectorIndex; j < unemployedProtectors.size(); j++)
            {
                unemployedProtectors[j] = unemployedProtectors[j + 1];
            }
            
            unemployedProtectors.pop_back();
            
        }
        
        if(firstWord == "Fire")
        {
            string nobleName;
            string ProtectorName;
            size_t nobleIndex;
            size_t ProtectorIndex;
            
            newFile >> nobleName >> ProtectorName;
            
            //check that the noble exists
            nobleIndex = checkNoble(nobleName, nobles);
            
            //check that Protector exists
            ProtectorIndex = checkProtector(ProtectorName, employedProtectors);
            
            unemployedProtectors.push_back(employedProtectors[ProtectorIndex]);
            
            nobles[nobleIndex]->fire(employedProtectors[ProtectorIndex]);
            
            for(size_t j = ProtectorIndex; j < employedProtectors.size() - 1; j++)
            {
                employedProtectors[j] = employedProtectors[j + 1];
            }
            
            employedProtectors.pop_back();
        }
        
        if(firstWord == "Status")
        {
            cout << "Status" << endl;
            cout << "======" << endl;
            status(unemployedProtectors, employedProtectors, nobles);
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
            
            for(Protector*& Protector : unemployedProtectors)
            {
                delete Protector;
                Protector = nullptr;
            }
            unemployedProtectors.clear();
            
            for(Protector* eProtector : employedProtectors)
            {
                delete eProtector;
                eProtector = nullptr;
            }
            employedProtectors.clear();
        }
    }
    
    newFile.close();
}
 
*/


