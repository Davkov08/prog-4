#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> edges;
bool vis[100];
queue<int> q;

void bfs() {
    if (q.empty()) return;
    int u = q.front();
    q.pop();
    cout << u << " ";
    for (auto e : edges) {
        if (e.first == u && !vis[e.second]) {
            vis[e.second] = true;
            q.push(e.second);
        }
    }
    bfs();
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        edges.push_back({v, u});
    }
    int start;
    cin >> start;
    q.push(start);
    vis[start] = true;
    bfs();
}
