#include <bits/stdc++.h>
using namespace std;

int dfs(int u, int t, int f, vector<pair<int,int>>& edges, vector<int>& caps, vector<bool>& vis) {
    if (u == t) return f;
    vis[u] = true;
    for (int i = 0; i < edges.size(); i++) {
        int v = edges[i].second;
        if (edges[i].first == u && caps[i] > 0 && !vis[v]) {
            int pushed = dfs(v, t, min(f, caps[i]), edges, caps, vis);
            if (pushed > 0) {
                caps[i] -= pushed;
                if (i % 2 == 0) caps[i + 1] += pushed;
                else caps[i - 1] += pushed;
                return pushed;
            }
        }
    }
    return 0;
}

int ford_fulkerson(int s, int t, vector<pair<int,int>> edges, vector<int> caps, int n) {
    int flow = 0;
    while (true) {
        vector<bool> vis(n, false);
        int f = dfs(s, t, INT_MAX, edges, caps, vis);
        if (f == 0) break;
        flow += f;
    }
    return flow;
}

int main() {
    //FF Killer test case
    vector<pair<int,int>> FF_killer = {
        {0,1}, {1,0},
        {0,2}, {2,0},
        {1,3}, {3,1},
        {2,1}, {1,2},
        {2,3}, {3,2}
    };
    vector<int> FF_killer_caps = {
        8,0, 8,0, 8,0, 1,0, 8,0
    };
    cout << "FF Killer max flow: " << ford_fulkerson(0,3,FF_killer,FF_killer_caps,4) << '\n';


    //CP4X8531 test case
    vector<pair<int,int>> cp4x8531 = {
        {0,1},{1,0}, {0,2},{2,0}, {0,3},{3,0},
        {1,6},{6,1}, {1,5},{5,1}, {1,4},{4,1},
        {2,5},{5,2}, {3,5},{5,3},
        {4,7},{7,4}, {5,7},{7,5}, {6,7},{7,6}
    };
    vector<int> cp4x8531_caps = {
        1,0, 1,0, 1,0,
        1,0, 1,0, 1,0,
        1,0, 1,0,
        1,0, 1,0, 1,0
    };
    cout << "CP4X8531 max flow: " << ford_fulkerson(0,7,cp4x8531,cp4x8531_caps,8) << '\n';


    //CS4234MFDemo test case
    vector<pair<int,int>> cs4234mfdemo = {
        {0,1},{1,0}, {0,2},{2,0}, {0,3},{3,0},
        {1,2},{2,1}, {1,5},{5,1}, {1,4},{4,1},
        {2,5},{5,2}, {2,3},{3,2}, {3,6},{6,3},
        {4,5},{5,4}, {4,7},{7,4}, {5,6},{6,5},
        {5,7},{7,5}, {6,7},{7,6}, {6,2},{2,6}
    };
    vector<int> cs4234mfdemo_caps={
        10,0, 5,0, 15,0,
        4,0, 15,0, 9,0,
        8,0, 4,0, 16,0,
        15,0, 10,0, 15,0,
        10,0, 10,0, 6,0
    };
    cout << "CS4234 MF Demo max flow: " << ford_fulkerson(0,7,cs4234mfdemo,cs4234mfdemo_caps,8) << '\n';


    //Matching with Capacity test case
    vector<pair<int,int>> mwc = {
        {0,1},{1,0},
        {0,2},{2,0},
        {1,3},{3,1},
        {1,4},{4,1},
        {2,4},{4,2},
        {3,5},{5,3},
        {4,5},{5,4}
    };
    vector<int> mwc_caps={
        1,0, 3,0, 99,0, 99,0, 99,0, 2,0, 2,0
    };
    cout << "Matching with Capacity max flow: " << ford_fulkerson(0,5,mwc,mwc_caps,6) << '\n';
}
