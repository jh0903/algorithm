#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int d[1001], id[1001], ti[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, k, w;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		vector<int> adj[1001];
		fill(d, d + 1001, 0);
		fill(id, id + 1001, 0);
		fill(ti, ti + 1001, 0);
		for (int i = 1; i <= n; i++) {
			cin >> d[i];
		}
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			id[y]++;
			adj[x].push_back(y);
		}
		cin >> w;
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (!id[i]) {
				q.push(i);
				ti[i] = d[i];
			}
		}
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (int nxt : adj[cur]) {
				id[nxt]--;
				ti[nxt] = max(ti[nxt], d[nxt] + ti[cur]);
				if (!id[nxt]) q.push(nxt);
			}
		}
		cout << ti[w]<<'\n';
	}
	return 0;
}