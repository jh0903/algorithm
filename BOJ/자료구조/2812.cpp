#include<iostream>
#include<stack>
#include<string>
using namespace std;

string str;
int n, k;
stack<char> s, tmp;

int main(void) {
    cin >> n >> k >> str;
    int si = str.size();
    for (int i = 0; i < si; i++) {
        if (s.empty()) {
            s.push(str[i]);
            continue;
        }
        while (k && !s.empty()) {
            if (s.top() < str[i]) {
                s.pop();
                k--;
            }
            else break;
        }
        s.push(str[i]);
    }
    while (k) {
        s.pop();
        k--;
    }
    while (!s.empty()) {
        tmp.push(s.top());
        s.pop();
    }
    while (!tmp.empty()) {
        cout << tmp.top();
        tmp.pop();
    }

    return 0;
}