#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string w;
int si, ans = 5;

void func(int le, int ri, int cnt) {
	if (ri <= le) {
		ans = min(ans, cnt);
		return;
	}
	if (w[le] == w[ri]) func(le + 1, ri - 1, cnt);
	else {
		if (cnt != 3) {
			func(le + 1, ri, cnt + 1);
			func(le, ri - 1, cnt + 1);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> w;
	si = w.size();
	func(0, si - 1, 0);
	if (ans > 3) cout << "-1" << '\n';
	else cout << ans << '\n';
	return 0;
}

/*
주어진 문자열을 팰린드롬 문자열로 만드는데 필요한 최소 횟수를 구하는 문제.
문자열의 시작, 끝에서 출발하는 포인터 le, ri를 만든다.
두 포인터가 가리키는 문자가 같으면 le+1, ri-1로 이동시키고,
다르면 le+1, ri과 le, ri-1로 이동시킨다.
두 포인터가 만나기 전까지 재귀 호출을 반복하면 답을 구할 수 있다.
*/