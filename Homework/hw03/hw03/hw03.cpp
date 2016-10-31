//
//  hw03.cpp
//  hw03
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
    
    void hire(Warrior& newWarrior)
    {
        army.push_back(&newWarrior);
    }
    
    void display()
    {
        cout << name << " has an army of " << army.size() << endl;
        for(Warrior* warrior : army)
        {
            cout << "       " << warrior->getName() << ": " << warrior->getStrength() << endl;
        }
    }
    
    void fire(const Warrior& firedWarrior)
    {
        cout << firedWarrior.getName() << ", you're fired! -- " << name << endl;
        
        for(size_t i = 0; i < army.size(); ++i)
        {
            if(army[i] == &firedWarrior)
            {
                for(size_t j = i; j < army.size(); ++j)
                {
                    army[j] = army[j + 1];
                }
            }
        }
        
        army.pop_back();
    }
    
    void battle(Noble& otherNoble)
    {
        double army1Total = 0;
        double army2Total = 0;
        
        cout << name << " battles " << otherNoble.name << endl;
        
        //add the strength of all the warriors in the first Noble's army
        for(Warrior* warrior : army)
        {
            army1Total = army1Total + warrior->getStrength();
        }
        
        //add the strength of all the warriors in the second Noble's army
        for(Warrior* warrior : otherNoble.army)
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
            cout << "He's dead, " << otherNoble.name << endl;
        }
        
        //if army2 is already dead
        else if(army2Total == 0)
        {
            cout << "He's dead, " << name << endl;
        }
        
        //if both armies have the same strength, all warriors in the army have a new strength of 0
        else if(army1Total == army2Total)
        {
            cout << "Mutual Annihilation: " << name << " and " << otherNoble.name << " die at each other's hands" << endl;
            
            for(Warrior* warrior : army)
            {
                warrior->setStrength(0);
            }
            
            for(Warrior* warrior : otherNoble.army)
            {
                warrior->setStrength(0);
            }

        }
        
        //if army1 has a higher strength, multiply the strength of all the warriors in army1 with the ratio, and set all the warriors in army2 with a new strength of 0
        else if(army1Total > army2Total)
        {
            cout << name << " defeats " << otherNoble.name << endl;
            
            double armyRatio = army2Total / army1Total;
            
            for(Warrior* warrior : army)
            {
                warrior->setStrength(warrior->getStrength() * armyRatio);
            }
            
            for (Warrior* warrior : otherNoble.army)
            {
                warrior->setStrength(0);
            }
        }
        
        //if army2 has a higher strength, multiply the strength of all the warriors in army2 with the ratio, and set all the warriors in army1 with a new strength of 0
        else
        {
            cout << otherNoble.name << " defeats " << name << endl;
            
            double armyRatio = army1Total / army2Total;
            
            for(Warrior* warrior : army)
            {
                warrior->setStrength(0);
            }
            
            for(Warrior* warrior : otherNoble.army)
            {
                warrior->setStrength(warrior->getStrength() * armyRatio);
            }
            
        }
        
    }
    
private:
    string name;
    vector<Warrior*> army;
};

int main()
{
    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");
    
    Warrior cheetah("Tarzan", 10);
    Warrior wizard("Merlin", 15);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);
    
    jim.hire(nimoy);
    lance.hire(theGovernator);
    art.hire(wizard);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(cheetah);
    
    jim.display();
    lance.display();
    art.display();
    linus.display();
    billie.display();
    
    art.fire(cheetah);
    art.display();
    
    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);
}


