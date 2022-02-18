#include<iostream>
#include<algorithm>
using namespace std;

int n, c;
int a[200001];

int binarysearch() {
	int st = 1, en = a[n - 1] - a[0];
	int ans = 0;
	while (st <= en) {
		int mid = (st + en) / 2;
		int cnt = 1, l = a[0];
		for (int i = 1; i < n; i++) {
			if (a[i] - l >= mid) {
				cnt++;
				l = a[i];
			}
		}
		if (cnt >= c) {
			st = mid + 1;
			ans = mid;
		}
		else {
			en = mid - 1;
		}
	}
	return ans;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	cout << binarysearch();
    
	return 0;
}