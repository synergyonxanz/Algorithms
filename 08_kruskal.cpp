#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    //           w,     {source, dest}
    cin >> n;
    vector<pair<int, pair<int, int>>> edges;
    unordered_map<int, int> sastaDJS;
    int i, j;
    for (i = 0; i < n; i++)
    {
        sastaDJS[i] = i;
        cin >> j;
        while (j)
        {
            int dest, w;
            cin >> dest >> w;
            edges.push_back({w, {i, dest}});
            j--;
        }
    }

    // * check edge list
    // for (auto edge : edges)
    // {
    //     cout << edge.first << " " << edge.second.first << "-" << edge.second.second << endl;
    // }

    vector<pair<int, int>> tree;

    sort(edges.begin(), edges.end(), [&](pair<int, pair<int, int>> &p1, pair<int, pair<int, int>> &p2)
         { return p1.first < p2.first; });
    int sum = 0;

    for (auto edge = edges.begin(); edge != edges.end(); edge++)
    {
        int src = (*edge).second.first;
        int dest = (*edge).second.second;
        int w = (*edge).first;

        if (sastaDJS[src] != sastaDJS[dest])
        {
            tree.push_back({src, dest});
            sum += w;
            int target = sastaDJS[src];
            for (auto &x : sastaDJS)
            {
                if (x.second == target)
                {
                    x.second = sastaDJS[dest];
                }
            }
        }
    }

    for (auto edge : tree)
    {
        cout << edge.first << " " << edge.second << endl;
    }

    cout << sum;

    return 0;
}

// 5
// 2
// 1 2
// 2 1
// 2
// 0 2
// 2 1
// 4
// 0 1
// 1 1
// 3 2
// 4 2
// 2
// 2 2
// 4 1
// 2
// 2 2
// 3 1
