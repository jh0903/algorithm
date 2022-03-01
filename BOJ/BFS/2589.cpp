#include<iostream>
#include<queue>
#include<memory.h>
#include<algorithm>
using namespace std;

char t[51][51];
int r, c, ans, dist[51][51];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
queue<pair<int, int>> q;

void bfs(int x, int y) {
	q.push({ x,y });
	dist[x][y] = 1;
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		ans = max(ans, dist[cur.first][cur.second] - 1);
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (dist[nx][ny] || t[nx][ny] == 'W') continue;
			q.push({ nx,ny });
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
		}
	}
	memset(&dist[0][0], 0, sizeof(dist));
}

int main(void) {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> t[i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (t[i][j] == 'L') bfs(i,j);
		}
	}
	cout << ans;

	return 0;
}