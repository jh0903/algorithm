#include<iostream>
#include<vector>
#include<memory.h>
#include<queue>
using namespace std;

int v, e, vis[20001];
vector<int> adj[20001];

void bfs() {
    queue<int> q;
    for (int i = 1; i <= v; i++) {
        if (vis[i]) continue;
        q.push(i);
        vis[i] = 1;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int nxt : adj[cur]) {
                if (vis[nxt]) continue;
                if (vis[cur] == 1) vis[nxt] = 2;
                else vis[nxt] = 1;
                q.push(nxt);
            }
        }
    }
}

bool check() {
    for (int i = 1; i <= v; i++) {
        for (int nxt : adj[i]) {
            if (vis[i] == vis[nxt]) return false;
        }
    }
    return true;
}

int main(void) {
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    while (k--) {
        cin >> v >> e;
        for (int i = 0; i < e; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bfs();
        if (check()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
        for (int i = 1; i <= v; i++) {
            adj[i].clear();
        }
        memset(&vis[0], 0, sizeof(vis));
    }

    return 0;
}