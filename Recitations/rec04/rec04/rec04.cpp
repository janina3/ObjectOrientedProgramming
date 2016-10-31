//
//  main.cpp
//  rec04
//
//  Created by Janina Soriano on 9/25/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//Task 1

/*
class Sandwich
{
public:
    
private:
    int bread;
    int cheese;
    double mayo;
    int tomato;
    double mustard;
};

int main()
{
    Sandwich mySandwich;
    
    return 0;
    
}
*/

//Task 2

/*
 class Sandwich
 {
 public:
 
 void display() const
 {
 cout << "Bread: " << bread << ", cheese: " << cheese << ", mayo: " << mayo << ", tomato: " << tomato << ", mustard: " << mustard << endl;
 }
 
 private:
 int bread;
 int cheese;
 double mayo;
 int tomato;
 double mustard;
 };
 
 int main()
 {
 Sandwich mySandwich;
 mySandwich.display();
 
 return 0;
 
 }
*/


//Task 3

/*
class Sandwich
{
public:
 
    void display() const
    {
        cout << "Bread: " << bread << ", cheese: " << cheese << ", mayo: " << mayo << ", tomato: " << tomato << ", mustard: " << mustard << endl;
    }
    
private:
    int bread = 2;
    int cheese = 1;
    double mayo = 1.0;
    int tomato = 2;
    double mustard = 0.5;
};
 
 

int main()
{
    Sandwich mySandwich;
    mySandwich.display();
    
    return 0;
    
}
*/


//Task 4

/*
class Sandwich
{
public:
    Sandwich(double amtMayo = 0.1) : mayo(amtMayo) {}
    
    void display() const
    {
        cout << "Bread: " << bread << ", cheese: " << cheese << ", mayo: " << mayo << ", tomato: " << tomato << ", mustard: " << mustard << endl;
    }
    
private:
    int bread;
    int cheese;
    double mayo;
    int tomato;
    double mustard;
};



int main()
{
    Sandwich mySandwich;
    mySandwich.display();
    
    return 0;
    
}
*/

//Task 5

/*
class Sandwich
{
public:
    Sandwich(int amtTomato = 2, int amtCheese = 1, double amtMustard = 0.5, double amtMayo = 1.0, int amtBread = 2) : tomato(amtTomato), cheese(amtCheese), mustard(amtMustard), mayo(amtMayo), bread(amtBread) {}
    
    void display() const
    {
        cout << "Bread: " << bread << ", cheese: " << cheese << ", mayo: " << mayo << ", tomato: " << tomato << ", mustard: " << mustard << endl;
    }
    
private:
    int bread;
    int cheese;
    double mayo;
    int tomato;
    double mustard;
};



int main()
{
    Sandwich mySandwich;
    mySandwich.display();
    
    return 0;
    
}
 */

//Task 6

/*
class Sandwich
{
public:
    Sandwich(int amtTomato = 2, int amtCheese = 1, double amtMustard = 0.5, double amtMayo = 1.0, int amtBread = 2) : tomato(amtTomato), cheese(amtCheese), mustard(amtMustard), mayo(amtMayo), bread(amtBread) {}
    
    void display() const
    {
        cout << "Bread: " << bread << ", cheese: " << cheese << ", mayo: " << mayo << ", tomato: " << tomato << ", mustard: " << mustard << endl;
    }
    
    //accessor methods
    int getBread() const
    {
        return bread;
    }
    
    int getCheese() const
    {
        return cheese;
    }
    
    double getMayo() const
    {
        return mayo;
    }
    
    int getTomato() const
    {
        return tomato;
    }
    
    double getMustard() const
    {
        return mustard;
    }
    
private:
    int bread;
    int cheese;
    double mayo;
    int tomato;
    double mustard;
};



int main()
{
    Sandwich mySandwich;
    mySandwich.display();
    
    cout << "Bread: " << mySandwich.getBread() << ", cheese: " << mySandwich.getCheese() << ", mayo: " << mySandwich.getMayo() << ", tomato: " << mySandwich.getTomato() << ", mustard: " << mySandwich.getMustard() << endl;
    
    return 0;
    
}
*/

//Task 7

/*
class Sandwich
{
public:
    Sandwich(int amtTomato = 2, int amtCheese = 1, double amtMustard = 0.5, double amtMayo = 1.0, int amtBread = 2) : tomato(amtTomato), cheese(amtCheese), mustard(amtMustard), mayo(amtMayo), bread(amtBread) {}
    
    void display() const
    {
        cout << "Bread: " << bread << ", cheese: " << cheese << ", mayo: " << mayo << ", tomato: " << tomato << ", mustard: " << mustard << endl;
    }
    
    //getter methods (accessor)
    int getBread() const
    {
        return bread;
    }
    
    int getCheese() const
    {
        return cheese;
    }
    
    double getMayo() const
    {
        return mayo;
    }
    
    int getTomato() const
    {
        return tomato;
    }
    
    double getMustard() const
    {
        return mustard;
    }
    
    //setter methods (mutators)
    void setBread(int amtBread)
    {
        bread = amtBread;
    }
    
    void setCheese(int amtCheese)
    {
        cheese = amtCheese;
    }
    
    void setMayo(double amtMayo)
    {
        mayo = amtMayo;
    }
    
    void setTomato(int amtTomato)
    {
        tomato = amtTomato;
    }
    
    void setMustard(double amtMustard)
    {
        mustard = amtMustard;
    }
private:
    int bread;
    int cheese;
    double mayo;
    int tomato;
    double mustard;
};



int main()
{
    Sandwich mySandwich;
    mySandwich.display();
    
    mySandwich.setCheese(4);
    
    cout << "Bread: " << mySandwich.getBread() << ", cheese: " << mySandwich.getCheese() << ", mayo: " << mySandwich.getMayo() << ", tomato: " << mySandwich.getTomato() << ", mustard: " << mySandwich.getMustard() << endl;
    
    return 0;
    
}
*/

//Task 8

/*
class Sandwich
{
public:
    Sandwich(int amtTomato = 2, int amtCheese = 1, double amtMustard = 0.5, double amtMayo = 1.0, const int amtBread = 2) : tomato(amtTomato), cheese(amtCheese), mustard(amtMustard), mayo(amtMayo), bread(amtBread) {}
    
    void display() const
    {
        cout << "Bread: " << bread << ", cheese: " << cheese << ", mayo: " << mayo << ", tomato: " << tomato << ", mustard: " << mustard << endl;
    }
    
    //getter methods (accessor)
    int getBread() const
    {
        return bread;
    }
    
    int getCheese() const
    {
        return cheese;
    }
    
    double getMayo() const
    {
        return mayo;
    }
    
    int getTomato() const
    {
        return tomato;
    }
    
    double getMustard() const
    {
        return mustard;
    }
    
    //setter methods (mutators)
    void setCheese(int amtCheese)
    {
        cheese = amtCheese;
    }
    
    void setMayo(double amtMayo)
    {
        mayo = amtMayo;
    }
    
    void setTomato(int amtTomato)
    {
        tomato = amtTomato;
    }
    
    void setMustard(double amtMustard)
    {
        mustard = amtMustard;
    }
private:
    const int bread;
    int cheese;
    double mayo;
    int tomato;
    double mustard;
};



int main()
{
    Sandwich mySandwich;
    mySandwich.display();
    
    mySandwich.setCheese(4);
    
    cout << "Bread: " << mySandwich.getBread() << ", cheese: " << mySandwich.getCheese() << ", mayo: " << mySandwich.getMayo() << ", tomato: " << mySandwich.getTomato() << ", mustard: " << mySandwich.getMustard() << endl;
    
    return 0;
    
}
*/

//Task 10

/*
class Sandwich
{
public:
    Sandwich(int amtTomato = 2, int amtCheese = 1, double amtMustard = 0.5, double amtMayo = 1.0, const int amtBread = 2) : tomato(amtTomato), cheese(amtCheese), mustard(amtMustard), mayo(amtMayo), bread(amtBread) {}
    
    void display() const
    {
        cout << "Bread: " << bread << ", cheese: " << cheese << ", mayo: " << mayo << ", tomato: " << tomato << ", mustard: " << mustard << endl;
    }
    
    //getter methods (accessor)
    int getBread() const
    {
        return bread;
    }
    
    int getCheese() const
    {
        return cheese;
    }
    
    double getMayo() const
    {
        return mayo;
    }
    
    int getTomato() const
    {
        return tomato;
    }
    
    double getMustard() const
    {
        return mustard;
    }
    
    //setter methods (mutators)
    void setCheese(int amtCheese)
    {
        cheese = amtCheese;
    }
    
    void setMayo(double amtMayo)
    {
        mayo = amtMayo;
    }
    
    void setTomato(int amtTomato)
    {
        tomato = amtTomato;
    }
    
    void setMustard(double amtMustard)
    {
        mustard = amtMustard;
    }
private:
    const int bread;
    int cheese;
    double mayo;
    int tomato;
    double mustard;
};

class SandwichTruck
{
public:
    void checkBeforeLeaving() const
    {
        for(Sandwich currentSandwich : sandwichOnTruck)
        {
            currentSandwich.display();
        }
    }
    
    void insertSandwich(const Sandwich& newSandwich)
    {
        sandwichOnTruck.push_back(newSandwich);
    }
private:
    vector<Sandwich> sandwichOnTruck;
    
};

int main()
{
    Sandwich mySandwich;
    mySandwich.display();
    
    mySandwich.setCheese(4);
    mySandwich.display();
    
    Sandwich tuna;
    tuna.setCheese(0);
    tuna.setMayo(5.0);
    tuna.setMustard(0);
    tuna.setTomato(0);
    
    tuna.display();
    
    SandwichTruck breadTruck;
    breadTruck.insertSandwich(mySandwich);
    breadTruck.insertSandwich(tuna);
    breadTruck.checkBeforeLeaving();
    
    return 0;
    
}
*/

//Task 11

class Sandwich
{
public:
    Sandwich(int amtTomato = 2, int amtCheese = 1, double amtMustard = 0.5, double amtMayo = 1.0, const int amtBread = 2) : tomato(amtTomato), cheese(amtCheese), mustard(amtMustard), mayo(amtMayo), bread(amtBread) {}
    
    void display() const
    {
        cout << "Bread: " << bread << ", cheese: " << cheese << ", mayo: " << mayo << ", tomato: " << tomato << ", mustard: " << mustard << endl;
    }
    
    //getter methods (accessor)
    int getBread() const
    {
        return bread;
    }
    
    int getCheese() const
    {
        return cheese;
    }
    
    double getMayo() const
    {
        return mayo;
    }
    
    int getTomato() const
    {
        return tomato;
    }
    
    double getMustard() const
    {
        return mustard;
    }
    
    //setter methods (mutators)
    void setCheese(int amtCheese)
    {
        cheese = amtCheese;
    }
    
    void setMayo(double amtMayo)
    {
        mayo = amtMayo;
    }
    
    void setTomato(int amtTomato)
    {
        tomato = amtTomato;
    }
    
    void setMustard(double amtMustard)
    {
        mustard = amtMustard;
    }
private:
    const int bread;
    int cheese;
    double mayo;
    int tomato;
    double mustard;
};

class SandwichTruck
{
public:
    void checkBeforeLeaving() const
    {
        for(Sandwich currentSandwich : sandwichOnTruck)
        {
            currentSandwich.display();
        }
    }
    
    void insertSandwich(const Sandwich& newSandwich)
    {
        sandwichOnTruck.push_back(newSandwich);
    }
private:
    vector<Sandwich> sandwichOnTruck;
    
};

int main()
{
    SandwichTruck breadTruck;
    
    Sandwich customer1;
    cout << "Customer 1: ";
    customer1.display();
    
    breadTruck.insertSandwich(customer1);
    
    Sandwich customer2;
    cout << "Customer 2: ";
    customer2.display();
    customer2.setMustard(0);
    cout << "New Customer 2: ";
    customer2.display();
    
    breadTruck.insertSandwich(customer2);
    
    Sandwich customer3(2, 2);
    cout << "Customer 3: ";
    customer3.display();
    
    breadTruck.insertSandwich(customer3);
    
    Sandwich customer4;
    cout << "Customer 4: ";
    customer4.display();
    
    breadTruck.insertSandwich(customer4);
    
    breadTruck.checkBeforeLeaving();
    
    
    return 0;
    
}
