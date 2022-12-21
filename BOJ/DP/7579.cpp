#include<iostream>
#include<algorithm>
using namespace std;

int n, m, sum, ans = 10005;
int mem[105], cost[105], t[105][10005];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> mem[i];
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		sum += cost[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			t[i][j] = t[i - 1][j];
			if (j - cost[i] >= 0)
				t[i][j] = max(t[i][j], t[i - 1][j - cost[i]] + mem[i]);
			if (t[i][j] >= m) ans = min(ans, j);
		}
	}
	cout << ans;
	return 0;
}

//배낭문제