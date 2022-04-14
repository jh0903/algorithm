#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m, idg[32001];
vector<int> adj[32001], ans;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        idg[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (!idg[i]) pq.push(i);
    }
    while (!pq.empty()) {
        int cur = pq.top(); pq.pop();
        ans.push_back(cur);
        for (int nxt : adj[cur]) {
            idg[nxt]--;
            if (!idg[nxt]) pq.push(nxt);
        }
    }
    for (int x : ans) cout << x << ' ';

    return 0;
}