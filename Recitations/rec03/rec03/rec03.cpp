//
//  rec03.cpp
//  rec03
//
//  Created by Janina Soriano on 9/18/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct Hydrocarbon
{
    vector<string> names;
    int numCarbon;
    int numHydrogen;
};

void openFile(ifstream& readMolecule);
void readFile(ifstream& readMolecule, vector<Hydrocarbon>& molecules);
size_t findHydrocarbon(const vector<Hydrocarbon>& molecules, int numCarbon, int numHydrogen);
void printHydrocarbons(const vector<Hydrocarbon>& molecules);

int main()
{
    vector<Hydrocarbon> molecules;
    ifstream readMolecule;
    openFile(readMolecule);
    readFile(readMolecule, molecules);
    printHydrocarbons(molecules);
}

void openFile(ifstream& readMolecule)
{
    //open file
    readMolecule.open("/Users/janinasoriano/School Work/Fall 2015/CS 1124/Recitations/rec02/chemicals.txt");
    //check if file opened
    if(!readMolecule)
    {
        cerr << "Couldn't open file" << endl;
        exit(0);
    }
}

size_t findHydrocarbon(const vector<Hydrocarbon>& molecules, int numCarbon, int numHydrogen)
{
    for(size_t index = 0; index < molecules.size(); ++index)
    {
        if(molecules[index].numCarbon == numCarbon && molecules[index].numHydrogen == numHydrogen)
        {
            return index;
        }
        //        else
        //        {
        //            return molecules.size();
        //        }
    }
    
    return molecules.size();
}

void readFile(ifstream& readMolecule, vector<Hydrocarbon>& molecules)
{
    string name;
    int numCarbon;
    int numHydrogen;
    char junk;
    size_t index;
    
    //read by line
    while(readMolecule >> name >> junk >> numCarbon >> junk >> numHydrogen)
    {
        //check molecules for formula duplicates
        index = findHydrocarbon(molecules, numCarbon, numHydrogen);
        
        if(index == molecules.size())
        {
            Hydrocarbon newMolecule;
            newMolecule.names.push_back(name);
            newMolecule.numCarbon = numCarbon;
            newMolecule.numHydrogen = numHydrogen;
            molecules.push_back(newMolecule);
        }
        else
        {
            molecules[index].names.push_back(name);
        }
        
    }
    
    readMolecule.close();
}

void printHydrocarbons(const vector<Hydrocarbon>& molecules)
{
    //find the highest number of carbons
    int highestCarbon = 0;
    
    for(size_t index = 0; index < molecules.size(); ++index)
    {
        if(molecules[index].numCarbon > highestCarbon)
        {
            highestCarbon = molecules[index].numCarbon;
        }
        
    }
    
    //int lowestCarbon = 1;
    
    for(int lowestCarbon = 1; lowestCarbon <= highestCarbon; ++lowestCarbon)
    {
        for(size_t index = 0; index < molecules.size(); ++index)
        {
//            cout << "Low: " << lowestCarbon << endl;
//            cout << "High: " << highestCarbon << endl;
            if(molecules[index].numCarbon == lowestCarbon)
            {
//                for(Hydrocarbon molecule : molecules)
//                {
                    cout << "C" << molecules[index].numCarbon << "H" << molecules[index].numHydrogen << endl;
                    for(string name : molecules[index].names)
                    {
                        cout << name << endl;
                    }
                    cout << endl;
//                }
            }
        }
    }
    
    
    
    
}





