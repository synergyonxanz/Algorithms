// {{0,1,43},{1,0,6},{-1,-1,0}}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            int n;
            cin >> n;
            mat[i][j] = (n == -1) ? 100000 : n;
        }
    }

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%5d", (mat[i][j] == 100000) ? -1 : mat[i][j]);
        }
        cout << endl;
    }

    return 0;
}