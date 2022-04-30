#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> ans;
    map<string, string> m1; //아이디, 이름
    map<int, string> m2; //몇번째로 출력되는 메세지인지, 메세지의 주어(아이디)
    for (string s : record) {
        vector<string> v;
        stringstream ss;
        string tmp;
        ss.str(s);
        while (ss >> tmp) v.push_back(tmp);
        if (v[0] == "Enter") {
            ans.push_back("님이 들어왔습니다.");
            m1[v[1]] = v[2];
            m2[ans.size() - 1] = v[1];
        }
        if (v[0] == "Leave") {
            ans.push_back("님이 나갔습니다.");
            m2[ans.size() - 1] = v[1];
        }
        if (v[0] == "Change") {
            m1[v[1]] = v[2];
        }
    }
    int si = ans.size();
    for (int i = 0; i < si; i++) {
        ans[i] = m1[m2[i]] + ans[i];
    }
    
    return ans;
}