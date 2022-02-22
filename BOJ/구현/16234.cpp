#include<iostream>
#include<queue>
#include<memory.h>
#include<cmath>
using namespace std;

#define X first
#define Y second

int n, l, r;
int arr[51][51], vis[51][51];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
queue<pair<int, int>> q, q1;

int bfs() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j]) continue;
			vis[i][j] = 1;
			q.push({ i,j });
			int c = 1, sum = arr[i][j];
			while (!q.empty()) {
				pair<int, int> cur = q.front(); q.pop();
				for (int k = 0; k < 4; k++) {
					int nx = cur.X + dx[k];
					int ny = cur.Y + dy[k];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					if (vis[nx][ny]) continue;
					int d = abs(arr[cur.X][cur.Y] - arr[nx][ny]);
					if (l <= d && d <= r) {
						sum += arr[nx][ny];
						c++;
						q.push({ nx,ny });
						vis[nx][ny] = 1;
						q1.push({ nx,ny });
					}
				}
			}
			if (c > 1) { 
				cnt++;
				arr[i][j] = sum / c;
			}
			while (!q1.empty()) {
				pair<int, int> cur = q1.front(); q1.pop();
				arr[cur.X][cur.Y] = sum / c;
			}
		}
	}
	memset(&vis[0][0], 0, sizeof(vis));
	return cnt;
}

int main(void) {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	while (1) {
		int c = bfs();
		if (!c) break;
		ans++;
	}
	cout << ans;

	return 0;
}