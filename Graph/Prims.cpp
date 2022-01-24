#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int n, m;                       // no of rows and coloums of matrix
const int N = 1e5 + 3;          // maximum numbre
vector<vector<int>> g[N];       // ha array of vectors aahe of type integer.
int cost = 0;                   // cost ya variable cha initialization tyala aatach eqaul to 0 kelay
vector<int> dist(N), parent(N); // destination and parent vector of type integer.
vector<bool> vis(N);            // boolean vector ekhayada node la visit kel ki nahi he check krayla to boolean kelay
const int INF = 1e9;            // infinite number

void primsMST(int source) // hoooo
{
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF; // distance of others infinity
    }

    set<vector<int>> s; 
    dist[source] = 0;   //distance of source
    s.insert({0, source});  //insert 0 with 0 cost
    while (!s.empty())   
    {
        auto x = *(s.begin());  //top element is extract
        s.erase(x); //delete after extracting
        vis[x[1]] = true; 
        int u = x[1];
        int v = parent[x[1]];
        int w = x[0];
        cout << u << " " << v << " " << w << "\n";
        cost += w;

        for (auto it : g[x[1]])  //iterating for next
        {
            if (vis[it[0]])
            {
                continue;
            }
            if (dist[it[0]] > it[1])
            {
                s.erase({dist[it[0]], it[0]});
                dist[it[0]] = it[1];
                s.insert({dist[it[0]], it[0]});
                parent[it[0]] = x[1];
            }
        }
    }
}
int main()
{

    cin >> n >> m; // will check  //input ghetle rows and col are dya lagte

    for (int i = 0; i < m; i++)
    {
        int u, v, w; // nodes ,edges,weight
        cin >> u >> v >> w;
        g[u].push_back({v, w}); // yala as a set insert kel  //you can assume like stack
        g[v].push_back({u, w});
    }

    primsMST(0);  // ya function la call kela
    cout << cost; // minimum cost print krnar ith
    return 0;
}