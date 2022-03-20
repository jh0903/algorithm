#include<iostream>
#include<memory.h>
#include<queue>
using namespace std;

int n, m, ans;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
bool arr[101][101], vis[101][101];

int check() {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j]) ret++;
        }
    }
    return ret;
}

void outside_air() {
    queue<pair<int, int>> q;
    q.push({ 0,0 });
    vis[0][0] = 1;
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (vis[nx][ny] || arr[nx][ny]) continue;
            vis[nx][ny] = 1;
            q.push({ nx,ny });
        }
    }
}

void melt() {
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j]) {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (!arr[nx][ny] && vis[nx][ny]) cnt++;
                }
                if (2 <= cnt) q.push({ i,j });
            }
        }
    }
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        arr[cur.first][cur.second] = 0;
    }
}

int main(void) {
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    while (1) {
        if (!check()) break;
        ans++;
        outside_air();
        melt();
        memset(&vis[0][0], 0, sizeof(vis));
    }
    cout << ans;
    return 0;
}