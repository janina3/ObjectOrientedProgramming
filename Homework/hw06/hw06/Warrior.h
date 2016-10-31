//
//  Warrior.h
//  hw06
//
//  Created by Janina Soriano on 11/12/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#ifndef __hw06__Warrior__
#define __hw06__Warrior__

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

namespace WarriorCraft
{
    class Noble;    //Forward declare Noble class
    
    class Warrior
    {
    public:
        Warrior(const std::string& theName, double theStrength);
        
        //Accesors
        std::string getName() const;
        
        double getStrength() const;
        
        std::string getNoble() const;
        
        //Modifiers
        void setName(const std::string& newName);
        
        void setStrength(const double newStrength);
        
        void setNoble(Noble& newNoble);
        
        void setNobleNull();
        
        //Other
//        void display() const;
        
        void runaway();
        
    private:
        std::string name;
        double strength;
        Noble* noble;
    };

    
    
}

#endif /* defined(__hw06__Warrior__) */
