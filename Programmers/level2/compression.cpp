#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s) {
    int answer = 1001;
    int si = s.size();
    for (int x = 1; x <= si; x++) {
        string str="";
        int cnt = 1;
        for (int i = 0; i < si; i += x) {
            if (i + x > si) {
                str += s.substr(i, si - i);
                break;
            }
            if (s.substr(i, x) == s.substr(i + x, x)) {
                cnt++;
            }
            else {
                if (cnt != 1) str += to_string(cnt) + s.substr(i, x);
                else str += s.substr(i, x);
                cnt = 1;
            }
        }
        int c = str.size();
        answer = min(answer, c);
    }
    return answer;
}