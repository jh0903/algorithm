#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m, idg[1001];
vector<int> adj[1001], ans;
queue<int> q;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int t, x, last;
        cin >> t;
        for (int i = 0; i < t; i++) {
            cin >> x;
            if (i) {
                adj[last].push_back(x);
                idg[x]++;
            }
            last = x;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!idg[i]) q.push(i);
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        ans.push_back(cur);
        for (int nxt : adj[cur]) {
            idg[nxt]--;
            if (!idg[nxt]) q.push(nxt);
        }
    }
    if (ans.size() != n) cout << 0;
    else {
        for (int x : ans) cout << x << '\n';
    }
    return 0;
}