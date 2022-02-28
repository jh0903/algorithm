#include<iostream>
#include<algorithm>
using namespace std;

int a[51];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] <= 0) { 
			break; 
		}
		if (i - 1 >= 0) {
			if (a[i] + a[i - 1] < a[i] * a[i - 1]) {
				ans += a[i] * a[i - 1];
				i--;
			}
			else {
				ans += a[i];
			}
		}
		else {
			ans += a[i];
		}
	}
	for (int i = 0; i <n; i++) {
		if (a[i] > 0) break;
		if (i + 1 < n) {
			if (a[i + 1] <= 0) {
				ans += a[i] * a[i + 1];
				i++;
			}
			else
				ans += a[i];
		}
		else
			ans += a[i];
	}
	cout << ans;

	return 0;
}