#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<memory.h>
using namespace std;

bool vis[1000001];
queue<pair<string, int>> q; //숫자, 횟수

string swap(string s, int st, int en) {
	char tmp = s[st];
	s[st] = s[en];
	s[en] = tmp;
	if (s[0] == '0') return "-1";
	return s;
}

int main(void) {
	string s;
	int k;
	cin >> s >> k;
	int si = s.size(), last = 0, ans = -1;
	q.push({ s, 0 });
	while (!q.empty()) {
		string n = q.front().first;
		int cnt = q.front().second; q.pop();
		if (cnt == k) {
			ans = max(ans, stoi(n));
			continue;
		}
		if (last != cnt) {
			memset(&vis[0], 0, sizeof(vis));
			last = cnt;
		}
		for (int i = 0; i < si; i++) {
			for (int j = i + 1; j < si; j++) {
				string x = swap(n, i, j);
				if (x == "-1") continue;
				if (vis[stoi(x)]) continue;
				q.push({ x, cnt + 1 });
				vis[stoi(x)] = true;
			}
		}
	}
	cout << ans;

	return 0;
}