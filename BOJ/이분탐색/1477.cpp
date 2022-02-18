#include<iostream>
#include<algorithm>
using namespace std;

int n, m, l;
int a[51];

int binarysearch() {
	int st = 1, en = l;
	int ans = 1000;
	while (st <= en) {
		int mid = (st + en) / 2, cnt = 0;
		int last = 0;
		for (int i = 0; i < n; i++) {
			while (last + mid < a[i]) {
				last += mid;
				cnt++;
			}
			last = a[i];
		}
		while (last + mid < l) {
			last += mid;
			cnt++;
		}
		if (cnt > m) {
			st = mid + 1;
		}
		else{
			en = mid - 1;
			ans = mid;
		}
	}
	return ans;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> l;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	cout << binarysearch();
	return 0;
}