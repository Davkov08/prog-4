#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100];
bool vis[100];

void dfs(int u) {
    vis[u] = true;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start;
    cin >> start;
    dfs(start);
}
