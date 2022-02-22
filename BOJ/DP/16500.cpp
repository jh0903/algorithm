#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> v;
int dp[101];

int main (void) {
	string a;
	cin >> a;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string b;
		cin >> b;
		v.push_back(b);
	}
	int si = a.size();
	dp[si] = 1;
	for (int i = si - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (v[j].size() + i > si) dp[i] = 0;
			else {
				if (a.substr(i, v[j].size()) == v[j] && dp[i + v[j].size()]) {
					dp[i] = 1;
					break;
				}
			}
		}
	}
	cout << dp[0];

	return 0;
}