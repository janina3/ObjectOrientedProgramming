//
//  rec02.cpp
//  rec02
//
//  Created by Janina Soriano on 9/11/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void openFile(ifstream& ifs);
void readFile(ifstream& ifs, vector<vector<string>>& chemicals);
void printIndexFor(const vector<vector<string>> chemicals);
void printRangedFor(const vector<vector<string>> chemicals);
void closeFile();

int main()
{
    ifstream newFile;
    vector<vector<string>> chemicals;
    openFile(newFile);
    readFile(newFile, chemicals);
    printIndexFor(chemicals);
    printRangedFor(chemicals);
    
    
    
    
}

void openFile(ifstream& ifs)
{
    //open file
   ifs.open("/Users/janinasoriano/Documents/School Work/Fall 2015/CS 1124/Recitations/rec02/chemicals.txt");
    //check if file opened
    if(!ifs)
    {
        cerr << "Couldn't open file" << endl;
        exit(0);
    }
    
}

void readFile(ifstream& ifs, vector<vector<string>>& chemicals)
{
    string chemicalName;
    string formula;
    vector<string> oneChemical;
    
    //read by line
    while(ifs >> chemicalName >> formula)
    {
        oneChemical.push_back(formula); //add to the chemical container
        oneChemical.push_back(chemicalName);
        chemicals.push_back(oneChemical); //add the chemical to the vector of chemicals
        oneChemical.pop_back(); //clear the chemical container
        oneChemical.pop_back();
    }
    

    
    
}

void printIndexFor(const vector<vector<string>> chemicals)
{
    cout << "Indexed For Loop:" << endl;
    cout << " " << endl;
    //print using the index
    for(size_t index = 0; index < chemicals.size(); index++)
    {
        cout << chemicals[index][0] << " " << chemicals[index][1] << endl;
    }
    cout << " " << endl;
    cout << "========================" << endl;
    cout << " " << endl;
}


void printRangedFor(const vector<vector<string>> chemicals)
{
    cout << "Ranged For Loop:" << endl;
    cout << " " << endl;
    //print without index
    for(vector<string> oneChemical : chemicals)
    {
        cout << oneChemical[0] << " " << oneChemical[1] << endl;
    }
}