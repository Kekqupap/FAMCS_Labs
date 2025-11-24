#include <iostream>

using namespace std;

char* _strncat (char* strDest, const char* strSource, size_t count)
{
    char strRes[1000];
    int sizeDest = 0;
    while(strDest[sizeDest]!='\0')
        sizeDest++;
    int sizeSource = 0;
    while(strSource[sizeSource]!='\0')
        sizeSource++;
    if(sizeSource<count)
    count=sizeSource;
    for(int i=0; i<sizeDest; i++)  
        strRes[i]=strDest[i];
    for(int i=0; i<count; i++)   
        strRes[sizeDest+i]=strSource[i];
    strRes[sizeDest+count]='\0';
    return strRes;
}

int main()
{
    char a[500];
    char b[500];
    int n;
    cout << "Enter 2 rows: ";
    cin >> a;
    cin >> b;
    cout << "Enter amount of chars to add from second row to the end of first: ";
    cin >> n;
    char* c = _strncat(a, b, n);
    cout << c;
    return 0;
}