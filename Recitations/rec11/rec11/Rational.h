//
//  Rational.h
//  rec11
//
//  Created by Janina Soriano on 11/13/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#ifndef __rec11__Rational__
#define __rec11__Rational__

#include <iostream>

namespace CS1124
{
    class Rational
    {
        //Overload input operator
        friend std::istream& operator>>(std::istream& is, Rational& rhs);
        
        //Overload output operator
        friend std::ostream& operator<<(std::ostream& os, const Rational& rat);
        
        //Overload equals-to operator
        friend bool operator==(const Rational& lhs, const Rational& rhs);

        
    public:
        Rational(int numerator = 0, int denominator = 1);
        
        //Accessors
        int getNum() const;
        
        int getDen() const;
        
        //Modifiers
        void setNum(int newNum);
        
        void setDen(int newDem);
        
        //Overload plus-equals operator
        Rational& operator+=(const Rational& rhs);
        
        //Overload pre-incrememnt operator
        Rational& operator++();
        
        //Overload post-increment operator
        Rational operator++(int dummy);
        
        void normalize();
        
        int greatestCommonDivisor(int x, int y);

        
    
    private:
        int num;
        int den;
        
        
    };
    
    //Overload non-member, non-friend addition operator
    Rational operator+(const Rational& lhs, const Rational& rhs);
    
    //Overload non-member, non-friend does-not-equal operator
    bool operator!=(const Rational& lhs, const Rational& rhs);
    
    //Overload non-member, non-friend pre-decrement operator
    Rational& operator--(Rational& rhs);
    
    //Overload non-member, non-friend post-decrement operator
    Rational operator--(Rational& lhs, int dummy);

}

#endif /* defined(__rec11__Rational__) */
