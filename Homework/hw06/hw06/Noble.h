//
//  Noble.h
//  hw06
//
//  Created by Janina Soriano on 11/12/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#ifndef __hw06__Noble__
#define __hw06__Noble__

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

namespace WarriorCraft
{
    class Warrior;  //Forward declare Warrior class
    
    class Noble
    {
        friend std::ostream& operator<<(std::ostream& os, const Noble& noble);
        
    public:
        Noble(const std::string& theName);
        
        std::string getName() const;
        
        void hire(Warrior& newWarrior);
        
//        void display() const;
        
        void fire(Warrior& firedWarrior);
        
        void remove(const Warrior& runaway);
        
        void battle(Noble& otherNoble);
        
    private:
        std::string name;
        std::vector<Warrior*> army;
    };

    
}

#endif /* defined(__hw06__Noble__) */
