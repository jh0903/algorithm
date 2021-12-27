#include<iostream>
#include<string>
using namespace std;

int a[1100001];

int main(void) {
	int n;
	cin >> n;
	a[1] = 1;
	for (int i = 2; i <= 1100001; i++) {
		if (a[i]) continue;
		for (int j = i * 2; j <= 1100001; j += i) {
			if (a[j]) continue;
			a[j] = 1;
		}
	}
	for (int i = n; i <= 1100001; i++) {
		if (a[i]) continue;
		string s = to_string(i);
		int si = s.size(), ch=1;
		for (int j = 0; j < si; j++) {
			if (s[j] != s[si - j - 1]) {
				ch = 0;
				break;
			}
		}
		if (ch) {
			cout << s;
			return 0;
		}
	}
	return 0;
}