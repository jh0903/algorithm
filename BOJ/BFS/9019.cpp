#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

int vis[10001];

int main(void) {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		queue<pair<int, string>> q;
		q.push({ a,"" });
		while (!q.empty()) {
			pair<int, string> cur = q.front(); q.pop();
			int n = cur.first;
			if (n == b) {
				cout << cur.second << '\n';
				break;
			}
			if (!vis[(n * 2) % 10000]) {
				q.push({ (n * 2) % 10000, cur.second + 'D' });
				vis[(n * 2) % 10000] = 1;
			}
			if (!vis[(10000 + n - 1) % 10000]) {
				q.push({ (10000 + n - 1) % 10000, cur.second + 'S' });
				vis[(10000 + n - 1) % 10000] = 1;
			}
			int le = (n % 1000) * 10 + n / 1000;
			if (!vis[le]) {
				q.push({ le, cur.second + 'L' });
				vis[le] = 1;
			}
			int ri = (n % 10) * 1000 + n / 10;
			if (!vis[ri]) {
				q.push({ ri, cur.second + 'R' });
				vis[ri] = 1;
			}
		}
		fill(vis, vis + 10001, 0);
	}
	return 0;
}