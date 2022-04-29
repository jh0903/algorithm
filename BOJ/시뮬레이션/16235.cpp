#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n, m, k, ans;
int a[15][15], food[15][15];
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
vector<int> v[15][15];
queue<pair<pair<int,int>, int>> dead;

void spring() {
    for (int i = 1; i <= n; i++) {
        for (int j =1; j <= n; j++) {
            if (v[i][j].empty()) continue;
            sort(v[i][j].begin(), v[i][j].end());
            int si = v[i][j].size();
            for (int id = 0; id < si; id++) {
                if (v[i][j][id] > food[i][j]) {
                    dead.push({ {i,j}, v[i][j][id] });
                    v[i][j].erase(v[i][j].begin() + id); 
                    id--;
                    si--;
                    continue;
                }
                food[i][j] -= v[i][j][id];
                v[i][j][id]++;
            }
        }
    }
}

void summer() {
    while (!dead.empty()) {
        pair<int, int> cur = dead.front().first;
        int half_age = dead.front().second / 2; dead.pop();
        food[cur.first][cur.second] += half_age;
    }
}

void fall() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (v[i][j].empty()) continue;
            for (int age : v[i][j]) {
                if (age % 5 != 0) continue;
                for (int id = 0; id < 8; id++) {
                    int nx = i + dx[id];
                    int ny = j + dy[id];
                    if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
                    v[nx][ny].push_back(1);
                }
            }
        }
    }
}

void winter() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            food[i][j] += a[i][j];
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            food[i][j] = 5;
        }
    }
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v[x][y].push_back(z);
    }
    while (k--) {
        spring();
        summer();
        fall();
        winter();
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans += v[i][j].size();
        }
    }
    cout << ans;

    return 0;
}