#include <iostream>
#include <vector>

using namespace std;

bool isCorrect(int x)
{
    if (x<1||x>10)
        return false;
    return true;
}

bool isSeadle(int _i, int _j, const vector <vector<int>>& _matrix)
{
    for(int i=0; i<_matrix[0].size(); i++)
    {
        if(_matrix[_i][_j]>_matrix[_i][i])
            return false;
    }
    for(int i=0; i<_matrix[0].size(); i++)
    {
        if(_matrix[_i][_j]<_matrix[i][_j])
            return false;
    }
    return true;
}

int main()
{
    int n, m;
    cout << "Enter size of matrix as n m: ";
    cin >> n >> m;
    while (!isCorrect(n)||!isCorrect(m))
    {
        cout << "Wrong type of input. Please, reenter n and m: ";
        cin >> n >> m;
    }
    cout << "Enter matrix: " << endl;;
    vector <vector<int>> matrix(n, vector <int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> matrix[i][j];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if((i+j)%2==0)
                matrix[i][j]=1;
    cout << "The matrix is: " << endl;
    for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                cout << matrix[i][j] << ' ';  
            cout << endl;
        }             
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            if(!matrix[i][j])
            {
                int sum = 0;
                for(int k=0; k<m; k++)
                sum+=matrix[i][k];
                cout << "Sum of " << i+1 << " row: " << sum << endl;
                break;
            }
    }
    int amountOfPoints = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(isSeadle(i, j, matrix))
                amountOfPoints++;
    cout << "Amount of seadle points: " << amountOfPoints << endl;
    return 0;
}