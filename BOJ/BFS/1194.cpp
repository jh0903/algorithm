#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

#define X first
#define Y second

int n, m, sx, sy, ans = 987654321;
int dist[55][55][64];
char arr[55][55];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
queue<pair<pair<int, int>, int>> q;

void bfs() {
    q.push({ {sx, sy}, 0 });
    dist[sx][sy][0] = 1;
    while (!q.empty()) {
        pair<int, int> cur = q.front().first;
        int key = q.front().second; q.pop();
        if (arr[cur.X][cur.Y] == '1') {
            ans = min(ans, dist[cur.X][cur.Y][key] - 1);
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (arr[nx][ny] == '#') continue;
            //열쇠 있으면
            if ('a' <= arr[nx][ny] && arr[nx][ny] <= 'f') {
                int nk = key | (1 << (arr[nx][ny] - 'a'));
                if (dist[nx][ny][nk]) continue;
                dist[nx][ny][nk] = dist[cur.X][cur.Y][key] + 1;
                q.push({ {nx,ny}, nk });
            }
            //문 있으면
            else if ('A' <= arr[nx][ny] && arr[nx][ny] <= 'F') {
                if (key & (1 << (arr[nx][ny] - 'A'))) {
                    if (dist[nx][ny][key]) continue;
                    dist[nx][ny][key] = dist[cur.X][cur.Y][key] + 1;
                    q.push({ {nx, ny}, key });
                }
            }
            //그 외 갈수 있는 곳
            else {
                if (dist[nx][ny][key]) continue;
                dist[nx][ny][key] = dist[cur.X][cur.Y][key] + 1;
                q.push({ {nx,ny}, key });
            }
        }
    }
}

int main(void) {
    ios::ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '0') {
                sx = i;
                sy = j;
            }
        }
    }
    bfs();
    if (ans == 987654321) cout << "-1";
    else cout << ans;

    return 0;
}