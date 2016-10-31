//
//  Rational.cpp
//  rec11
//
//  Created by Janina Soriano on 11/13/15.
//  Copyright (c) 2015 Janina Soriano. All rights reserved.
//

#include "Rational.h"
#include <iostream>

using namespace std;

namespace CS1124
{
    Rational::Rational(int numerator, int denominator) : num(numerator), den(denominator) {}
    
    //Accessor
    int Rational::getNum() const
    {
        return num;
    }
    
    int Rational::getDen() const
    {
        return den;
    }
    
    //Modifiers
    void Rational::setNum(int newNum)
    {
        num = newNum;
    }
    
    void Rational::setDen(int newDem)
    {
        den = newDem;
    }
    
    //Overload plus-equals operator
    Rational& Rational::operator+=(const Rational& rhs)
    {
        if(den == rhs.den)
        {
            num += rhs.num;
        }
        else
        {
            int commonDen = den * rhs.den;
            num += commonDen;
            den = commonDen;
        }
        return *this;
    }
    
    //Overload pre-incrememnt operator
    Rational& Rational::operator++()
    {
        num += den;
        return *this;
    }
    
    //Overload post-increment operator
    Rational Rational::operator++(int dummy)
    {
        Rational previous(*this);
        num += den;
        return previous;
    }
    
    //Normalize rational number
    void Rational::normalize()
    {
        if(num > den)
        {
            int gcd = greatestCommonDivisor(den, num);
            num = num/gcd;
            den = den/gcd;
        }
        else if(num < den)
        {
            int gcd = greatestCommonDivisor(num, den);
            num = num/gcd;
            den = den/gcd;
        }
        else
        {
            num = 1;
            den = 1;
        }
        
        if((num < 0 && den < 0) || (num > 0 && den < 0))
        {
            num *= -1;
            den *= -1;
        }
        
    }
    
    int Rational::greatestCommonDivisor(int x, int y)
    {
        while (y != 0)
        {
            int temp = x % y;
            x = y;
            y = temp;
        }
        return x;
    }
    
    //Overload input operator
    istream& operator>>(istream& is, Rational& rhs)
    {
        int numerator;
        int denominator;
        char slash;
        is >> numerator >> slash >> denominator;
        rhs.num = numerator;
        rhs.den = denominator;
        return is;
    }
    
    //Overload output operator
    ostream& operator<<(ostream& os, const Rational& rat)
    {
        Rational norm(rat.getNum(), rat.getDen());
        norm.normalize();
        os << norm.num << "/" << norm.den;
        return os;
    }
    
    //Overload equals-to operator
    bool operator==(const Rational& lhs, const Rational& rhs)
    {
        return(lhs.num == rhs.num && lhs.den == rhs.den);
    }
    
    //Overload non-member, non-friend addition operator
    Rational operator+(const Rational& lhs, const Rational& rhs)
    {
        Rational sum(lhs);
        sum += rhs;
        return sum;
        
    }
    
    //Overload non-member, non-friend does-not-equal operator
    bool operator!=(const Rational& lhs, const Rational& rhs)
    {
        return(!(lhs == rhs));
    }
    
    //Overload non-member, non-friend pre-decrement operator
    Rational& operator--(Rational& rhs)
    {
        rhs.setNum(rhs.getNum() - rhs.getDen());
        return rhs;
    }
    
    //Overload non-member, non-friend post-decrement operator
    Rational operator--(Rational& lhs, int dummy)
    {
        Rational previous(lhs);
        lhs.setNum(lhs.getNum() - lhs.getDen());
        return previous;
    }

}