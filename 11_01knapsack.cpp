#include <bits/stdc++.h>
using namespace std;
int solve(vector<pair<int, int>> &v, int i, int w)
{
    if (i == v.size() - 1)
    {
        return (v[i].first <= w) ? v[i].second : 0;
    }

    int skip = solve(v, i + 1, w);
    int take = INT_MIN;
    if (v[i].first <= w)
    {
        take = v[i].second + solve(v, i + 1, w - v[i].first);
    }

    return max(take, skip);
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n); //{weight, profit}

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    int capacity;
    cin >> capacity;

    cout << solve(v, 0, capacity);

    return 0;
}