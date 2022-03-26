#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;

int n, m, ans = 1000000000, arr[51][51], dist[51][51];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
vector<int> tmp;
vector<pair<int, int>> v;
queue<pair<int, int>> q;

int bfs() {
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (dist[nx][ny] || arr[nx][ny] == 1) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({ nx,ny });
        }
    }
    int ma = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] != 1 && !dist[i][j]) return 1000000000;
            if (!arr[i][j] && ma < dist[i][j]) ma = dist[i][j];
        }
    }
    return ma - 1;
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                v.push_back({ i,j });
            }
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (i < v.size() - m) tmp.push_back(0);
        else tmp.push_back(1);
    }
    do {
        for (int i = 0; i < v.size(); i++) {
            if (tmp[i]) {
                q.push({ v[i].first, v[i].second });
                dist[v[i].first][v[i].second] = 1;
            }
        }
        ans = min(ans, bfs());
        memset(&dist[0][0], 0, sizeof(dist));
    } while (next_permutation(tmp.begin(), tmp.end()));
    
    if (ans == 1000000000) cout << "-1";
    else cout << ans;

    return 0;
}