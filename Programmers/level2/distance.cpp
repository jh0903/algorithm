#include <string>
#include <vector>

using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

bool ch2(vector<string>& v, int x, int y, int lx, int ly) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
        if (nx == lx && ny == ly) continue;
        if (v[nx][ny] == 'P') {
            return false;
        }
    }
    return true;
}

bool ch(vector<string>& v, int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
        if (v[nx][ny] == 'P') return false;
        if (v[nx][ny] == 'O') {
            if (!ch2(v, nx,ny, x, y)) return false;
        }
    }
    return true;
}

int func(vector<string>& v) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (v[i][j] == 'P') {
                if (!ch(v, i, j)) return 0;
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (auto& a : places) {
        answer.push_back(func(a));
    }
    return answer;
}