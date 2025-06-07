#include <bits/stdc++.h>
using namespace std;

int pivot(vector<int> &v, int l, int r)
{
    int p = v[l];
    int i = l;
    int j = r;
    while (i < j)
    {
        while (i < r && v[i] <= p)
        {
            i++;
        }
        while (j > l && v[j] > p)
        {
            j--;
        }
        if (i < j)
            swap(v[i], v[j]);
    }
    swap(v[j], v[l]);
    return j;
}

void quickSort(vector<int> &v, int l, int r)
{
    if (l >= r)
        return;
    int p = pivot(v, l, r);
    quickSort(v, l, p - 1);
    quickSort(v, p + 1, r);
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

    quickSort(v, 0, n - 1);

    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}