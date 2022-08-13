#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define X first
#define Y second

int r, q, ans1, ans2;
bool vis[64][64];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void circulate(int x, int y, int si, vector<vector<int>>& a, vector<vector<int>>& tmp) {
    for (int i = 0; i < si; i++) {
        tmp[x][y + i] = a[x + si - 1 - i][y];
    }
    for (int i = 0; i < si; i++) {
        tmp[x + i][y + si - 1] = a[x][y + i];
    }
    for (int i = 0; i < si; i++) {
        tmp[x + si - 1][y + i] = a[x + si - 1 - i][y + si - 1];
    }
    for (int i = 0; i < si; i++) {
        tmp[x + i][y] = a[x + si - 1][y + i];
    }
}

void divide(int si, vector<vector<int>>& a) {
    int ssi = 1 << si;
    int siz = 1 << (si - 1);
    vector<vector<int>> tmp = a;
    for (int i = 0; i < r; i += ssi) {
        for (int j = 0; j < r; j += ssi) {
            for (int k = 0; k < siz; k++) {
                circulate(i + k, j + k, ssi - 2 * k, a, tmp);
            }
        }
    }
    a = tmp;
}

void melt(vector<vector<int>>& a) {
    queue<pair<int, int>> q;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            if (!a[i][j]) continue;
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || ny < 0 || nx >= r || ny >= r) continue;
                if (!a[nx][ny]) continue;
                cnt++;
            }
            if (cnt < 3) {
                q.push({ i,j });
            }
        }
    }
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        a[cur.X][cur.Y]--;
    }
}

int bfs(int x, int y, vector<vector<int>>& a) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    vis[x][y] = 1;
    int cnt = 0; //덩어리의 크기
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        cnt++;
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || ny < 0 || nx >= r || ny >= r)continue;
            if (!a[nx][ny] || vis[nx][ny]) continue;
            q.push({ nx,ny });
            vis[nx][ny] = 1;
        }
    }
    return cnt;
}

int main(void) {
    ios::ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> r >> q;
    r = 1 << r;
    vector<vector<int>> a(r, vector<int>(r));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            cin >> a[i][j];
        }
    }
    while (q--) {
        int x;
        cin >> x;
        divide(x, a);
        melt(a);
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            if (!a[i][j]) continue;
            ans1 += a[i][j];
            if (vis[i][j]) continue;
            ans2 = max(ans2, bfs(i, j, a));
        }
    }
    cout << ans1 << '\n' << ans2;

    return 0;
}