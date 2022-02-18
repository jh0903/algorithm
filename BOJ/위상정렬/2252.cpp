#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> ans, adj[32001];
int idg[32001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		idg[b]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!idg[i]) {
			q.push(i);

		}
	}
	while (!q.empty()) {
		ans.push_back(q.front());
		for (int i = 0; i < adj[q.front()].size(); i++) {
			idg[adj[q.front()][i]]--;
			if (idg[adj[q.front()][i]] == 0) {
				q.push(adj[q.front()][i]);
			}
		}
		q.pop();

	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}