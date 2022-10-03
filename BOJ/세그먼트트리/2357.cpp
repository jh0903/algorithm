#include<iostream>
#include<algorithm>
using namespace std;

int n, m, k;
int arr[1000001], tree_min[4000001], tree_max[4000001];

int init_min(int node, int st, int en) {
    if (st == en) {
        tree_min[node] = arr[st];
        return tree_min[node];
    }
    int mid = (st + en) / 2;
    int left = init_min(node * 2, st, mid);
    int right = init_min(node * 2 + 1, mid + 1, en);

    return tree_min[node] = min(left, right);
}

int init_max(int node, int st, int en) {
    if (st == en) {
        tree_max[node] = arr[st];
        return tree_max[node];
    }
    int mid = (st + en) / 2;
    int left = init_max(node * 2, st, mid);
    int right = init_max(node * 2 + 1, mid + 1, en);

    return tree_max[node] = max(left, right);
}

int find_min(int node, int st, int en, int le, int ri) {
    if (le > en || ri < st) return 1000000001;
    if (le <= st && en <= ri) return tree_min[node];

    int mid = (st + en) / 2;
    int left = find_min(node * 2, st, mid, le, ri);
    int right = find_min(node * 2 + 1, mid + 1, en, le, ri);

    return min(right, left);
}

int find_max(int node, int st, int en, int le, int ri) {
    if (le > en || ri < st) return 0;
    if (le <= st && en <= ri) return tree_max[node];

    int mid = (st + en) / 2;
    int left = find_max(node * 2, st, mid, le, ri);
    int right = find_max(node * 2 + 1, mid + 1, en, le, ri);

    return max(right, left);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    init_min(1, 0, n - 1);
    init_max(1, 0, n - 1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << find_min(1, 0, n - 1, a - 1, b - 1) << ' ';
        cout << find_max(1, 0, n - 1, a - 1, b - 1) << '\n';
    }

    return 0;
}