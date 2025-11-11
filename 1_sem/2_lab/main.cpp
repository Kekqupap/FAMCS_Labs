#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL));
    int n;
    double arr[10000];
    cout << "Enter the size of array: ";
    cin >> n;
    while(n>10000)
    {
        cout << "Size must be less than 10000: ";
        cin >> n;
    }
    cout << "Enter 0, if you want to enter values of elements" << endl;
    cout << "Enter 1, if you want random values of elements" << endl;
    bool flag;
    cin >> flag;
    if(flag)
    {
        double a, b;
        cout << "Enter bounds of values of elements [a; b]: ";
        cin >> a >> b;
        for(int i=0; i<n; i++)
            arr[i]=(rand()%10000)*1./10000*(b-a)+a;
    }
    else
    {
        cout << "Enter value for every element of array: " << endl;
        for(int i=0; i<n; i++)
            cin >> arr[i];
    }
    cout << "Your array is: ";
    for (int i=0; i<n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    double p;
    int amountLessP = 0;
    cout << "Enter P, to find all elements, that less than P: ";
    cin >> p;
    for(int i=0; i<n; i++)
        if(arr[i]<p)
            amountLessP++;
    cout << "Amount of elements less than P: "<< amountLessP << endl;
    int posLastNeg;
    for(int i=0; i<n; i++)
        if(arr[i]<0)
            posLastNeg=i;
    int sumOfIntPart = 0;
    for(int i=posLastNeg+1; i<n; i++)
        sumOfIntPart+=floor(arr[i]);
    cout << "Sum of integer parts of elements after last negative elemnt: " << sumOfIntPart << endl;
    for (int i=0; i<n; i++)
        if (arr[i]<p)
            for (int j=i-1; j>=0; j--)
                if(arr[j]>=p)
                {
                    swap(arr[i], arr[j]);
                    swap(i, j);
                }
    cout << "Now, your array is: ";
    for (int i=0; i<n; i++)
        cout << arr[i] << ' ';
    return 0;
}