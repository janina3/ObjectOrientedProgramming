//
//  main.cpp
//  rec08
//
//  CS 1124
//  N14209086
//
//  Created by Janina Soriano on 10/23/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#include <vector>
#include <iostream>

using namespace std;

class Instrument
{
public:
    virtual void makeSound() const = 0;
    virtual void play() const = 0;
};

class MILL
{
public:
    void receiveInstr(Instrument& newInst)
    {
        Instrument* instPtr = &newInst;
        instPtr->makeSound();
        if(instruments.size() == 0)
        {
            instruments.push_back(instPtr);
        }
        else
        {
            for(size_t i = 0; i < instruments.size(); i++)
            {
                if(instruments[i] == nullptr)
                {
                    instruments[i] = instPtr;
                }
                else
                {
                    instruments.push_back(instPtr);
                    break;
                }
            }
        }
    }
    
    void dailyTestPlay() const
    {
        for(size_t i = 0; i < instruments.size(); i++)
        {
            if(instruments[i] == nullptr)
            {
                i++;
            }
            else
            {
                instruments[i]->makeSound();
            }
        }
    }
    
    Instrument* loanOut()
    {
        for(size_t i = 0; i < instruments.size(); i++)
        {
            if(instruments[i] != nullptr)
            {
                Instrument* rental = instruments[i];
                instruments[i] = nullptr;
                return rental;
            }
        }
        
        return nullptr;
    }
    
private:
    vector<Instrument*> instruments;
};

class Brass : public Instrument
{
public:
    Brass(int mpSize) : mouthpiece(mpSize) {};
    
    void makeSound() const override
    {
        cout << "To make a sound... blow on a mouthpiece of size " << mouthpiece << endl;
    }
    
private:
    unsigned int mouthpiece;
};

class String : public Instrument
{
public:
    String(int p) : pitch(p) {};
    
    void makeSound() const override
    {
        cout << "To make a sound... bow a string with pitch " << pitch << endl;
    }
    
private:
    unsigned int pitch;
};

class Percussion : public Instrument
{
public:
    void makeSound() const override
    {
        cout << "To make a sound... hit me" << endl;
    }
    
private:
    
};

class Trumpet : public Brass
{
public:
    Trumpet(int mpSize) : Brass(mpSize) {};
    
    void play() const override
    {
        cout << "Toot";
    }
};

class Trombone : public Brass
{
public:
    Trombone(int mpSize) : Brass(mpSize) {};
    
    void play() const override
    {
        cout << "Blat";
    }
};

class Violin : public String
{
public:
    Violin(int p) : String(p) {};
    
    void play() const override
    {
        cout << "Screech";
    }
};

class Cello : public String
{
public:
    Cello(int p) : String(p) {};
    
    void play() const override
    {
        cout << "Squawk";
    }
};

class Cymbal : public Percussion
{
public:
    Cymbal() : Percussion() {};
    
    void play() const override
    {
        cout << "Crash";
    }
};

class Drum : public Percussion
{
public:
    Drum() : Percussion() {};
    
    void play() const override
    {
        cout << "Boom";
    }
};
    
class Musician {
public:
    Musician() : instr( NULL ) {}
    void acceptInstr( Instrument & i ) { instr = &i; }
    Instrument* giveBackInstr( ) {
        Instrument* tmp(instr);
        instr = NULL;
        return tmp;
    }
    void testPlay() const {
        if( instr )
            instr->makeSound();
        else
            cerr << "have no instr\n";
    }
    
    void perform() const
    {
        if(instr != nullptr)
        {
            instr->play();
        }
    }
    
private:
    Instrument* instr;
};

class Orch
{
public:
    void addPlayer(Musician& newMusician)
    {
        if(orchestra.size() != 25)
        {
            orchestra.push_back(&newMusician);
        }
        else
        {
            cout << "Can't add musician. Maximum orchestra size reached." << endl;
        }
    }
    
    void play() const
    {
        for(size_t i = 0; i < orchestra.size(); i++)
        {
            orchestra[i]->perform();
        }
        cout << endl;
    }
    
private:
    vector<Musician*> orchestra;
};

/*
// PART ONE
int main()
{
    
     cout << "Define some instruments ----------------------------------------\n";
     Drum drum;
     Cello cello(673);
     Cymbal cymbal;
     Trombone tbone( 4 );
     Trumpet trpt( 12 ) ;
     Violin violin( 567 ) ;
    
     // use the debugger to look at the mill
     cout << "Define the MILL ------------------------------------------------\n";
     MILL mill;
    
     cout << "Put the instruments into the MILL ------------------------------\n";
     mill.receiveInstr( trpt );
     mill.receiveInstr( violin );
     mill.receiveInstr( tbone );
     mill.receiveInstr( drum );
     mill.receiveInstr( cello );
     mill.receiveInstr( cymbal );
    
     cout << "Daily test -----------------------------------------------------\n";
     cout << endl;
     cout << "dailyTestPlay()" << endl;
     mill.dailyTestPlay();
     cout << endl;
    
     cout << "Define some Musicians-------------------------------------------\n";
     Musician j;
     Musician jj;
     Musician q;
    
     cout << "TESTING: q.acceptInstr( *mill.loanOut() );-----------------------\n";
     q.testPlay();
     cout << endl;
     q.acceptInstr( *mill.loanOut() );
     cout << endl;
     q.testPlay();
     cout << endl;
     cout << "dailyTestPlay()" << endl;
     mill.dailyTestPlay();
    
     cout << endl << endl;
    
     q.testPlay();
     cout << endl;
     mill.receiveInstr( *q.giveBackInstr() );
     j.acceptInstr( *mill.loanOut() );
     q.acceptInstr( *mill.loanOut() );
     cout << endl;
     q.testPlay();
     cout << endl;
     j.testPlay();
     cout << endl;
     cout << "dailyTestPlay()" << endl;
     mill.dailyTestPlay();
    
     cout << "TESTING: mill.receiveInstr( *q.giveBackInstr() ); -------------\n";
    
     // fifth
     mill.receiveInstr( *q.giveBackInstr() );
     cout << "TESTING: mill.receiveInstr( *j.giveBackInstr() ); -------------\n";
     mill.receiveInstr( *j.giveBackInstr() );
    
    
     cout << endl;
     cout << "dailyTestPlay()" << endl;
     mill.dailyTestPlay();
     cout << endl;
    
     cout << endl;
    
}
*/

int main()
{
    // The initialization phase
    
    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone( 4 );
    Trumpet trpt( 12 ) ;
    Violin violin( 567 ) ;
    
    MILL mill;
    mill.receiveInstr( trpt );
    mill.receiveInstr( violin );
    mill.receiveInstr( tbone );
    mill.receiveInstr( drum );
    mill.receiveInstr( cello );
    mill.receiveInstr( cymbal );
    
    Musician bob;
    Musician sue;
    Musician mary;
    Musician ralph;
    Musician jody;
    Musician morgan;
    
    Orch orch;
    
    
    
    // THE SCENARIO
    
    //Bob joins the orchestra without an instrument.
    orch.addPlayer(bob);
    
    //The orchestra performs
    cout << "orch performs\n";
    orch.play();
    
    //Sue gets an instrument from the MIL2 and joins the orchestra.
    sue.acceptInstr( *mill.loanOut() );
    orch.addPlayer(sue);
    
    //Ralph gets an instrument from the MIL2.
    ralph.acceptInstr( *mill.loanOut() );
    
    //Mary gets an instrument from the MIL2 and joins the orchestra.
    mary.acceptInstr( *mill.loanOut() );
    orch.addPlayer(mary);
    
    //Ralph returns his instrument to the MIL2.
    mill.receiveInstr( *ralph.giveBackInstr() );
    
    //Jody gets an instrument from the MIL2 and joins the orchestra.
    jody.acceptInstr( *mill.loanOut() );
    orch.addPlayer(jody);
    
    // morgan gets an instrument from the MIL2
    morgan.acceptInstr( *mill.loanOut() );
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    
    //Ralph joins the orchestra.
    orch.addPlayer(ralph);
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    
    // bob gets an instrument from the MIL2
    bob.acceptInstr( *mill.loanOut() );
    
    // ralph gets an instrument from the MIL2
    ralph.acceptInstr( *mill.loanOut() );
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    
    //Morgan joins the orchestra.
    orch.addPlayer(morgan);
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    
}

