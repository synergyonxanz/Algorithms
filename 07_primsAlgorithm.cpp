#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<vector<int>>> adj(n);
    for (int i = 0; i < n; i++)
    {
        int edges;
        cin >> edges; // edges from that node
        for (int j = 0; j < edges; j++)
        {
            int w, dest;
            cin >> dest >> w;
            adj[i].push_back({w, dest});
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<pair<int, int>> tree;
    vector<int> v(n, 0);

    pq.push({0, {0, -1}});
    int sum = 0;
    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();
        int w = node.first;
        int adjNode = node.second.first;
        if (v[adjNode])
            continue;
        v[adjNode] = 1;
        sum += w;
        for (auto n : adj[adjNode])
        {
            if (!v[n[1]])
            {
                pq.push({n[0], {n[1], adjNode}});
            }
        }
        if (node.second.second == -1)
            continue;
        tree.push_back({node.second});
    }

    for (auto i : tree)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl
         << sum;

    return 0;
}

// 3
// 2
// 1 5
// 2 1
// 2
// 0 5
// 2 3
// 2
// 0 1
// 1 3