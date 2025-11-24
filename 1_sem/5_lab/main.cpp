#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool isEmpty(const string &str)
{
    for(int i=0; i<str.size(); i++)
        if(str[i]!=' ')
            return false;
    return true;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    vector <string> strings;
    string bufferStr;
    while(getline(fin, bufferStr))       
        strings.push_back(bufferStr); 
    vector <pair<int, int>> emptyStrings;
    for(int i=0; i<strings.size(); i++)
    {
        if(isEmpty(strings[i]))
        {
            int pos = i;
            int amount = 1;
            for (int j=i+1; isEmpty(strings[j]); j++, i=j)
                amount++;
            emptyStrings.push_back({pos, amount});
        }
    }
    for(int i=0; i<emptyStrings.size(); i++)
        fout << emptyStrings[i].first+1 << ' ' << emptyStrings[i].second << endl;
}
