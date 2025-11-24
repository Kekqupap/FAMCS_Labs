#ifndef FRACTION_H
#define FRACTION_H
#include <string>
#include <iostream>


class Fraction
{
    public:
        Fraction() = delete;
        Fraction(const Fraction &f);
        Fraction(std::string str);
        virtual ~Fraction();
        int getNum();
        int getDen();
        Fraction operator+(Fraction &);
        Fraction operator-(Fraction &);
        Fraction operator*(Fraction &);
        Fraction operator/(Fraction &);
        friend std::ostream & operator <<(std::ostream &, const Fraction &);
        friend std::istream & operator >>(std::istream &, Fraction &);
        Fraction(int a, int b);
        double decimal();
    protected:

    private:
        int numerator, denominator;
        void reduction();
};

#endif // FRACTION_H
