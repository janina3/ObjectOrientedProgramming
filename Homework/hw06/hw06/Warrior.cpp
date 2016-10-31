//
//  Warrior.cpp
//  hw06
//
//  Created by Janina Soriano on 11/12/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#include "Warrior.h"
#include "Noble.h"

using namespace std;

namespace WarriorCraft
{

    Warrior::Warrior(const string& theName, double theStrength) : name(theName), strength(theStrength) {}
    
    //Accesors
    string Warrior::getName() const
    {
        return name;
    }

    double Warrior::getStrength() const
    {
        return strength;
    }
    
    string Warrior::getNoble() const
    {
        return noble->getName();
    }
    
    //Modifiers
    void Warrior::setName(const string& newName)
    {
        name = newName;
    }
    
    void Warrior::setStrength(const double newStrength)
    {
        strength = newStrength;
    }

    void Warrior::setNoble(Noble& newNoble)
    {
        noble = &newNoble;
    }
    
    void Warrior::setNobleNull()
    {
        noble = nullptr;
    }
    
    //Other
    //void Warrior::display() const
    //{
    //    cout << "       " << name << ": " << strength << endl;
    //}

    void Warrior::runaway()
    {
        if(noble != nullptr)
        {
            cout << name << " flees in terror, abandoning his lord, " << noble->getName() << endl;
            noble->Noble::remove(*this);
            noble = nullptr;
        }
    }
}

