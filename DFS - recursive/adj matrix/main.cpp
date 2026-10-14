#include <bits/stdc++.h>
using namespace std;

int n, m;
int mat[100][100];
bool vis[100];

void dfs(int u) {
    vis[u] = true;
    cout << u << " ";
    for (int v = 0; v < n; v++) {
        if (mat[u][v] && !vis[v]) dfs(v);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        mat[u][v] = 1;
        mat[v][u] = 1;
    }
    int start;
    cin >> start;
    dfs(start);
}
