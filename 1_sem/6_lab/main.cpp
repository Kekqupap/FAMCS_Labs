#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
    cout << "Enter fraction as whpr num/dem or num/dem: ";
    string str;
    getline(cin, str);
    cout << "Enter fraction as num dem: ";
    int a, b;
    cin >> a >> b;
    cout << "Enter fraction as num/dem: ";
    Fraction drob1(str), drob2(a, b), drob3(1, 1);
    cin >> drob3;
    cout << "The sum of first and second fractions is " << drob1+drob2 << endl;
    cout << "The subtraction of second and third fractions is " << drob2-drob3 << endl;
    cout << "The multiplication of first and third fractions is " << drob1*drob3 << endl;
    cout << "The division of second and first fractions is " << drob2/drob1 << endl;
    cout << "The third fraction in decimal view is " << drob3.decimal();
    return 0;
}
