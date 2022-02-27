#include<iostream>
#include<algorithm>
using namespace std;

int n, m, ans, a[100001];
long long sum;

int binarysearch() {
	int ans = 0;
	long long st = *max_element(a, a+n), en = sum;
	while (st <= en) {
		long long mid = (st + en) / 2, cnt = 1, s = 0;
		for (int i = 0; i < n; i++) {
			if (s + a[i] <= mid) {
				s += a[i];
			}
			else {
				cnt++;
				s = a[i];
			}
		}
		if (cnt <= m) {
			en = mid - 1;
			ans = mid;
		}
		else {
			st = mid + 1;
		}
	}
	return ans;
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	cout << binarysearch();

	return 0;
}