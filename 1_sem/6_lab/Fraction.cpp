#include "Fraction.h"
#include <algorithm>

int gcd (int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd (b, a % b);
}

void Fraction::reduction()
{
    if(denominator!=0)
    {
        int n = gcd(abs(numerator), denominator);
        numerator/=n;
        denominator/=n;
    }
    else
    {
        numerator=10e6;
        denominator=1;
    }
}

Fraction::Fraction(std::string str)
{
    if(str.find(' ')!=-1)
    {
        int n=stoi(str.substr(0, str.find(' ')));
        numerator=stoi(str.substr(str.find(' ')+1, str.find(' ')-str.find('/')-1));
        if(str[0]=='-')
            numerator*=-1;
        denominator=stoi(str.substr(str.find('/')+1, str.size()-str.find('/')));
        numerator+=n*denominator;
    }
    else
    {
        numerator=stoi(str.substr(0, str.find('/')));
        denominator=stoi(str.substr(str.find('/')+1, str.size()-str.find('/')));
    }
    reduction();
}

Fraction::Fraction(int a, int b)
{
    numerator=a;
    denominator=b;
    reduction();
}

Fraction::Fraction(const Fraction &f)
{
    numerator=f.numerator;
    denominator=f.denominator;
}

double Fraction::decimal()
{
    return (double)numerator/denominator;
}

Fraction Fraction::operator+(Fraction &drob)
{
    int new_den=denominator*drob.denominator;
    int new_num=numerator*drob.denominator+drob.numerator*denominator;
    return Fraction(new_num, new_den);
}

Fraction Fraction::operator-(Fraction &drob)
{
    int new_den=denominator*drob.denominator;
    int new_num=numerator*drob.denominator-drob.numerator*denominator;
    return Fraction(new_num, new_den);
}

Fraction Fraction::operator*(Fraction &drob)
{
    int new_den=denominator*drob.denominator;
    int new_num=numerator*drob.numerator;
    return Fraction(new_num, new_den);
}

Fraction Fraction::operator/(Fraction &drob)
{
    int new_den=denominator*drob.numerator;
    int new_num=numerator*drob.denominator;
    return Fraction(new_den*new_num/abs(new_den), abs(new_den));
}

std::ostream & operator <<(std::ostream &out, const Fraction &drob)
{
    if (drob.numerator/drob.denominator!=0)
    {
        out << drob.numerator/drob.denominator;
        if (drob.numerator%drob.denominator!=0)
            out << ' ' << abs(drob.numerator%drob.denominator) << '/' << drob.denominator;
    }
    else if (drob.numerator%drob.denominator!=0)
        out << drob.numerator << '/' << drob.denominator;
    else
        out << 0;
    return out;
}

std::istream & operator >>(std::istream &in, Fraction &drob)
{
    char c;
    in >> drob.numerator >> c >> drob.denominator;
    drob.reduction();
    return in;
}

int Fraction::getNum()
{
    return numerator;
}

int Fraction::getDen()
{
    return denominator;
}

Fraction::~Fraction()
{
    //dtor
}
