#include<iostream>
using namespace std;

int ans = 987654321, ch[6], arr[11][11];
bool vis[11][11];

bool vis_check(int c, int si) {
    int x = c / 10;
    int y = c % 10;
    for (int i = 0; i < si; i++) {
        for (int j = 0; j < si; j++) {
            //범위 넘으면 false
            if (x + i >= 10 || y + j >= 10) return false;
            //칸에 적힌 수가 0이거나, 이미 색종이가 붙어있다면 false
            if (!arr[x + i][y + j] || vis[x + i][y + j]) return false;
        }
    }
    //색종이를 붙였다고 표시한다. (vis 배열의 값을 1로)
    for (int i = 0; i < si; i++) {
        for (int j = 0; j < si; j++) {
            vis[x+i][y+j] = 1;
        }
    }
    return true;
}

//vis 배열의 값을 다시 false로 바꾸는 함수
void vis_false(int c, int si) {
    int x = c / 10;
    int y = c % 10;
    for (int i = 0; i < si; i++) {
        for (int j = 0; j < si; j++) {
            vis[x + i][y + j] = 0;
        }
    }
}

void dfs(int c, int cnt) {
    if (cnt >= ans) return; //ans보다 cnt가 크면 더 확인할 필요 없으므로 return
    //기저 조건
    if (c == 100) {
        ans = min(ans, cnt);
        return;
    }
    
    int x = c / 10;
    int y = c % 10;
    //칸에 적힌 수가 0이거나 이미 색종이가 붙어있으면 다음 칸 호출
    if (!arr[x][y] || vis[x][y]) { 
        dfs(c + 1, cnt);
        return; 
    }
    //색종이를 붙여본다.
    for (int i = 1; i <=5; i++) {
    	//색종이를 붙일 수 있는지 확인
        bool ret = vis_check(c, i);
        //붙일 수 있다면
        if (ret) {
            //색종이도 쓸 수 있다면 붙인다.
            if (ch[i] < 5) {
                ch[i]++;
                dfs(c + 1, cnt + 1);
                ch[i]--;
            }
            //vis 배열의 값을 false로
            vis_false(c, i);
        }
        //붙일 수 없다면 더 큰 크기의 색종이도 붙일 수 없으므로 break
        else break;
    }
}

int main(void) {
    ios::ios_base::sync_with_stdio(false); cin.tie(0);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> arr[i][j];
        }
    }
    dfs(0, 0);
    if (ans == 987654321) cout << "-1";
    else cout << ans;
          
    return 0;
}