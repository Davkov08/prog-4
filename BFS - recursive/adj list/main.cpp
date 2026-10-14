#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100];
bool vis[100];
queue<int> q;

void bfs() {
    if (q.empty()) return;
    int u = q.front();
    q.pop();
    cout << u << " ";
    for (int v : adj[u]) {
        if (!vis[v]) {
            vis[v] = true;
            q.push(v);
        }
    }
    bfs();
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
    q.push(start);
    vis[start] = true;
    bfs();
}
