#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &v)
{
    int i, j;
    for (i = 1; i < v.size(); i++)
    {
        int j = i - 1;
        while (j >= 0 && v[j] > v[i])
        {
            j--;
        }
        int t = v[i];
        for (int k = i; k > j; k--)
        {
            v[k] = v[k - 1];
        }
        v[j + 1] = t;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    insertionSort(v);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}