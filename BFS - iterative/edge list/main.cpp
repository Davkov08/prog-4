#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> edges;
bool vis[100];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    vis[start] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (auto e : edges) {
            if (e.first == u && !vis[e.second]) {
                vis[e.second] = true;
                q.push(e.second);
            }
        }
    }
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
    bfs(start);
}
