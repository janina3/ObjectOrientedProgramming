//
//  Noble.cpp
//  hw06
//
//  Created by Janina Soriano on 11/12/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#include "Noble.h"
#include "Warrior.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace WarriorCraft
{

    Noble::Noble(const string& theName) : name(theName) {}

    string Noble::getName() const
    {
        return name;
    }
    
    void Noble::hire(Warrior& newWarrior)
    {
        army.push_back(&newWarrior);
        newWarrior.setNoble(*this);
    }
    
    //void Noble::display() const
    //{
    //    cout << name << " has an army of " << army.size() << endl;
    //    for(Warrior* warrior : army)
    //    {
    //        warrior->display();
    //    }
    //}

    void Noble::fire(Warrior& firedWarrior)
    {
        cout << firedWarrior.getName() << ", you're fired! -- " << name << endl;
        
        firedWarrior.setNobleNull();
        
        for(size_t i = 0; i < army.size(); ++i)
        {
            if(army[i] == &firedWarrior)
            {
                for(size_t j = i; j < army.size() - 1; ++j)
                {
                    army[j] = army[j + 1];
                }
            }
        }
        
        army.pop_back();
    }

    void Noble::remove(const Warrior &runaway)
    {
        for(size_t i = 0; i < army.size(); ++i)
        {
            if(army[i] == &runaway)
            {
                for(size_t j = i; j < army.size() - 1; ++j)
                {
                    army[j] = army[j + 1];
                }
            }
        }
    
        army.pop_back();
    }

    void Noble::battle(Noble& otherNoble)
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

    ostream& operator<<(std::ostream& os, const Noble& noble)
    {
        os << noble.name << " has an army of " << noble.army.size() << endl;
        for(Warrior* warrior : noble.army)
        {
            os << "       " << warrior->getName() << ": " << warrior->getStrength() << endl;
        }
        
        return os;
    }
}
