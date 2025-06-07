// {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int edges;
    vector<vector<vector<int>>> adj(n);
    for (int i = 0; i < n; i++)
    {
        cin >> edges; // no of edges for a node
        for (int j = 0; j < edges; j++)
        {
            int dest, w;
            cin >> dest >> w;
            adj[i].push_back({dest, w});
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dists(n, INT_MAX);
    int s = 2;
    dists[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto edge : adj[node])
        {
            int w = edge[1];
            int newNode = edge[0];

            if (dist + w < dists[newNode])
            {
                dists[newNode] = dist + w;
                pq.push({dists[newNode], newNode});
            }
        }
    }

    for (auto i : dists)
    {
        cout << i << " ";
    }

    return 0;
}