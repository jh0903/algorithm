#include<iostream>
#include<vector>
using namespace std;

int ans;
int dx[9] = { 0,-1,-1,0,1,1,1,0,-1 };
int dy[9] = { 0,0,-1,-1,-1,0,1,1,1 };

vector<vector<pair<int, int>>> move_fish(vector<vector<pair<int, int>>> v) {
    for (int x = 1; x <= 16; x++) {
        bool find = false;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (v[i][j].first == x) {
                    find = true;
                    int dir = v[i][j].second;
                    for (int k = 0; k < 9; k++) {
                        int nx = i + dx[(dir + k)%9];
                        int ny = j + dy[(dir + k)%9];
                        if (nx == i && ny == j) continue;
                        if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;
                        if (v[nx][ny].first == 17) continue; //상어면 건너뛴다.
                        //물고기들끼리 자리 바꿈
                        v[i][j] = v[nx][ny];
                        v[nx][ny] = { x, (dir + k) % 9 };
                        break;
                    }
                }
                if (find) break;
            }
            if (find) break;
        }
    }
    return v;
}

void func(int x, int y, int sum, vector<vector<pair<int, int>>> v) {
    int sh_dir = v[x][y].second;
    sum += v[x][y].first;
    v[x][y] = { 17, sh_dir };

    v = move_fish(v);
    
    //상어가 먹을 물고기를 택한다.
    v[x][y] = { 0,0 };
    bool ch = false;
    for (int i = 1; i <= 4; i++) {
        int nx = x + dx[sh_dir] * i;
        int ny = y + dy[sh_dir] * i;
        if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;
        if (nx == x && ny == y) continue;
        if (!v[nx][ny].first) continue;
        ch = true;
        func(nx, ny, sum, v);
    }
    //잡아먹을 물고기가 없으면
    if (!ch) {
        ans = max(ans, sum);
    }
}

int main(void) {
    ios::ios_base::sync_with_stdio(false); cin.tie(0);
    vector<vector<pair<int,int>>> v;
    for (int i = 0; i < 4; i++) {
        vector<pair<int, int>> tmp;
        for (int j = 0; j < 4; j++) {
            int a, b;
            cin >> a >> b;
            tmp.push_back({ a,b });
        }
        v.push_back(tmp);
    }
    func(0, 0, 0, v);
    cout << ans;

    return 0;
}