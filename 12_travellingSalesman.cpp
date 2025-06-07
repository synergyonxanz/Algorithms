#include <bits/stdc++.h>
using namespace std;

int ans = 0;
vector<int> minRoute;
void tsp(vector<vector<int>> &adj, int count, vector<bool> &visited, vector<int> &route)
{
    if (count == adj.size())
    {
        int pathSum = 0;
        for (int j = 1; j < route.size(); j++)
        {
            pathSum += adj[route[j - 1]][route[j]];
        }
        pathSum += adj[route.back()][0];
        if (ans == 0 || pathSum < ans)
        {
            ans = pathSum;
            minRoute = route;
        }
        return;
    }

    for (int i = 1; i < adj.size(); i++)
    {
        if (!visited[i] && i != route.back())
        {
            visited[i] = 1;
            route.push_back(i);
            tsp(adj, count + 1, visited, route);
            visited[i] = 0;
            route.pop_back();
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }
    vector<bool> visited(n, 0);
    vector<int> route = {0};

    tsp(adj, 1, visited, route);
    cout << ans << endl;
    for (auto i : minRoute)
    {
        cout << i + 1 << "->";
    }
    cout << 1;

    return 0;
}

// 4
// 0 10 15 20
// 10 0 25 25
// 15 25 0 30
// 20 25 30 0
// ans : 80