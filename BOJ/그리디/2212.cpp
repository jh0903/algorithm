#include<iostream>
#include<algorithm>
using namespace std;

int a[10001], b[10001];

int main(void) {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 1; i < n; i++) {
		b[i-1]=a[i]-a[i-1];
	}
	sort(b, b + n -1);
	int ans = 0;
	for (int i = 0; i < n - k; i++) {
		ans += b[i];
	}
	cout << ans;

	return 0;
}