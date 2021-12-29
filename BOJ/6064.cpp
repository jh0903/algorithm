#include<iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		while (1) {
			while (x < y) {
				x += m;
			}
			while (y < x) {
				y += n;
			}
			if (x == y) {
				cout << x << '\n';
				break;
			}
			if (x > m * n || y > m * n) {
				cout << "-1" << '\n';
				break;
			}
		}
	}
	return 0;
}