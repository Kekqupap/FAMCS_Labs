#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    unsigned int k;
    cout << "Enter k, where k is power of your precision (10^-k): ";
    cin >> k;
    long double e = 1;
    for(int i=0; i<k; i++)
        e/=10;
    long double x;
    cout << "Enter x: ";
    cin >> x;
    long double sum = 0;
    long double koef = 1;
    for (int i=0; fabs(koef)>e; i++)
    {        
        sum+=koef;
        koef*=-(2*i+1)*x/(2*i+2);
    }
    cout.precision(k);
    cout << "Your result is " << sum << endl;
    return 0;
}