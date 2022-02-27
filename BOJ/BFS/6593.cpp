#include<iostream>
#include<queue>
#include<tuple>
#include<memory.h>
using namespace std;

int l, r, c, dist[31][31][31];
char building[31][31][31];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void bfs(queue<tuple<int, int, int>> &q) {
	while (!q.empty()) {
		int i, j, k;
		tie(i, j, k) = q.front(); q.pop();
		if (building[i][j][k] == 'E') {
			cout << "Escaped in " << dist[i][j][k] - 1 << " minute(s)." << '\n';
			return;
		}
		for (int d = 0; d < 4; d++) {
			int nx = j + dx[d];
			int ny = k + dy[d];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (dist[i][nx][ny] || building[i][nx][ny] == '#') continue;
			dist[i][nx][ny] = dist[i][j][k] + 1;
			q.push({ i,nx,ny });
		}
		if (i + 1 < l) {
			if (!dist[i + 1][j][k] && building[i + 1][j][k] != '#') {
				dist[i+1][j][k] = dist[i][j][k] + 1;
				q.push({ i + 1,j,k });
			}
		}
		if (i - 1 >= 0) {
			if (!dist[i - 1][j][k] && building[i - 1][j][k] != '#') {
				dist[i - 1][j][k] = dist[i][j][k] + 1;
				q.push({ i - 1,j,k });
			}
		}
	}
	cout << "Trapped!" << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (1) {
		cin >> l >> r >> c;
		if (!l && !r && !c) break;
		queue<tuple<int, int, int>> q;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> building[i][j][k];
					if (building[i][j][k] == 'S') {
						q.push({ i,j,k });
						dist[i][j][k] = 1;
					}
				}
			}
		}
		bfs(q);
		memset(&dist[0][0][0], 0, sizeof(dist));
	}

	return 0;
}