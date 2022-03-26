#include<iostream>
#include<memory.h>
using namespace std;

int n, ans, arr[501][501], dp[501][501];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (arr[nx][ny] <= arr[x][y]) {
            dp[x][y] = max(dp[x][y], 0);
            continue;
        }
        if (dp[nx][ny] != -1) {
            dp[x][y] = max(dp[x][y], dp[nx][ny] + 1);
        }
        else {
            dfs(nx, ny);
            dp[x][y] = max(dp[x][y], dp[nx][ny] + 1);
        }
   }
}

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    memset(&dp[0][0], -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] != -1) continue;
            dfs(i, j);
            ans = max(ans, dp[i][j] + 1);
        }
    }
    cout << ans;

    return 0;
}