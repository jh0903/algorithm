#include<iostream>
using namespace std;

typedef long long ll;
int n, m, k;
ll arr[1000001], tree[4000001];

/*
- 세그먼트 트리 만드는 함수
(현재 노드번호(1부터 시작), 시작 범위, 마지막 범위)
1. 주어진 범위를 반으로 나눔
2. 왼쪽 범위 재귀호출
3. 오른쪽 범위 재귀호출
4. 반복
*/
ll init(int node, int st, int en) {
    if (st == en) { //기저 조건: 리프노드일 때
        tree[node] = arr[st];
        return tree[node];
    }
    int mid = (st + en) / 2;
    ll left = init(node * 2, st, mid);
    ll right = init(node * 2 + 1, mid + 1, en);

    return tree[node] = left + right;
}

//구간 합 구하는 함수
ll sum(int node, int st, int en, int le, int ri) {
    if (le > en || ri < st) return 0; //완전히 겹치지 않을 때
    if (le <= st && en <= ri) return tree[node]; //완전히 속해있을 때

    //일부만 걸쳐있는 경우
    int mid = (st + en) / 2;
    ll left = sum(node * 2, st, mid, le, ri);
    ll right = sum(node * 2 + 1, mid + 1, en, le, ri);
    
    return left + right;
}

//값 변경하는 함수
void update(int node, ll dif, int st, int en, int id) {
    if (id > en || id < st) return; //id가 범위에 없으면 return
    tree[node] += dif;
    
    //리프노드가 아니라면 계속 탐색한다.
    if (st != en) {
        int mid = (st + en) / 2;
        update(node * 2, dif, st, mid, id);
        update(node * 2 + 1, dif, mid + 1, en, id);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    init(1, 0, n - 1);
    for (int i = 0; i < m + k; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            ll dif = c - arr[b - 1];
            arr[b - 1] = c;
            update(1, dif, 0, n - 1, b - 1);
        }
        else {
            cout << sum(1, 0, n - 1, b - 1, c - 1)<<'\n';
        }
    }

    return 0;
}