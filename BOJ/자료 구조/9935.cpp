#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(void) {
	string s, e;
	cin >> s >> e;
	int ss = s.size(), se = e.size();
	stack<char> st, tmp;
	for (int i = 0; i < ss; i++) {
		st.push(s[i]);
		if (st.top() == e[se-1]) {
			for (int j = 0; j < se; j++) {
				if (st.empty()) break;
				if (st.top() == e[se - j - 1]) {
					tmp.push(st.top());
					st.pop();
				}
				else break;
			}
		}
		if (tmp.size() == se) {
			while (!tmp.empty()) {
				tmp.pop();
			}
		}
		else {
			while (!tmp.empty()) {
				st.push(tmp.top());
				tmp.pop();
			}
		}
	}
	while (!st.empty()) {
		tmp.push(st.top());
		st.pop();
	}
	if (tmp.empty()) {
		cout << "FRULA";
	}
	else {
		while (!tmp.empty()) {
			cout << tmp.top();
			tmp.pop();
		}
	}
	return 0;
}