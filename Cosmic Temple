#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

#define int long long int
#define deb(x) cout << (#x) << " - " << x << "\n"
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
ull M = 1000000007;

using namespace std;

/*

                   0
                  / \
                 2   3
                    / \
                   4   1

For node  0,
0 -> 2 = 1
0 -> 3 = 1
0 -> 4 = 2
0 -> 1 = 2
dist[0] = 1 + 1 + 2 + 2 = 6

For node 1,
1 -> 0 = 2
1 -> 3 = 1
1 -> 4 = 2
1 -> 2 = 3
dist[1] = 2 + 1 + 2 + 3 = 8

For node 2,
2 -> 0 = 1
2 -> 3 = 2
2 -> 4 = 3
2 -> 1 = 3
dist[2] = 1 + 2 + 3 + 3 = 9

For node 3,
3 -> 0 = 1
3 -> 2 = 2
3 -> 4 = 1
3 -> 1 = 1
dist[3] = 1 + 2 + 1 + 1 = 5

For node 4,
4 -> 0 = 2
4 -> 2 = 3
4 -> 3 = 1
4 -> 1 = 2
dist[4] = 2 + 3 + 1 + 2 = 8

*/

void initializePreflow(vector<vector<int>> &graph, vector<int> &dist, vector<int> &count, int node, int parent)
{
    for (auto child : graph[node])
    {
        if (child != parent)
        {
            initializePreflow(graph, dist, count, child, node);
            count[node] += count[child];
            dist[node] += dist[child] + count[child];
        }
    }
}

void finalFlow(vector<vector<int>> &graph, vector<int> &dist, vector<int> &count, int node, int parent)
{
    for (auto child : graph[node])
    {
        if (child != parent)
        {
            dist[child] = dist[node] - count[child] + count.size() - count[child];
            finalFlow(graph, dist, count, child, node);
        }
    }
}

void solve_testcase()
{
    int n, u, v;
    cin >> n;
    vector<vector<int>> graph(n);
    vector<int> dist(n, 0), count(n, 1);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    initializePreflow(graph, dist, count, 0, -1);
    finalFlow(graph, dist, count, 0, -1);

    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << '\n';
}

int32_t main()
{
    // *********************
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // *********************

    // Driver Function Starts Here

    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        solve_testcase();
    }

    // Driver Function Ends Here
    return 0;
}
