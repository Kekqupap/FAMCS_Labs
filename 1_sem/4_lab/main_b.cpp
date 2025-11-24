#include <iostream>
#include <vector>

using namespace std;

bool isPolyndrom(char* str)
{
    int size=0;
    while(str[size]!='\0')
        size++;
    for(int i=0; i<size/2+1; i++)
        if(str[i]!=str[size-i-1]||str[i]<'0'||str[i]>'9')
            return false;
    return true;
}

int main()
{
    char a[300];
    gets_s(a);
    int posSpace1=0;
    int posSpace2=0;
    vector <char*> polyndroms;
    for(int i=0; a[i]!='\0'; i++)
    {
        if((a[i]==' '&&a[i]!=a[i+1])||(a[i]!=' '&&i==0))
        {
            posSpace1=i;
            posSpace2=posSpace1;
            do
            {
                posSpace2++;
            } while (a[posSpace2]!=' '&&a[posSpace2]!='\0');
            i=posSpace2-1;
        }
        else
            continue;
        if (!posSpace1)
            posSpace1--;
        if (posSpace2=='0')
            posSpace2--;
        char* bufferStr = new char[300];
        for(int j=0; j<posSpace2-posSpace1-1; j++)
            bufferStr[j]=a[posSpace1+j+1];
        bufferStr[posSpace2-posSpace1-1]='\0';
        if(isPolyndrom(bufferStr))
            polyndroms.push_back(bufferStr);
    }
    switch (polyndroms.size())
    {
    case 0:
        cout << "There is no such polyndroms :(";
        break;
    case 1:
        cout << polyndroms[0];
        break;
    default:
        cout << polyndroms[1];
        break;
    }
    return 0;
}