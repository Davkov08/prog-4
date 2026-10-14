#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> edges;
bool vis[100];

void dfs(int start) {
    stack<int> st;
    st.push(start);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (vis[u]) continue;
        vis[u] = true;
        cout << u << " ";
        for (auto e : edges) {
            if (e.first == u && !vis[e.second]) st.push(e.second);
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
    dfs(start);
}
