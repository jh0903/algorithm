#include <string>
#include <vector>
using namespace std;

bool ans = true;

void make_fullbinarytree(string &s){
    int si = s.size();
    int n = 2;
    while(1){
        if(n - 1 >= si) break;
        n *= 2;
    }
    int diff = n-1-si;
    string tmp = "";
    for(int i=0;i<diff;i++) tmp+="0";
    s = tmp + s;
}

//더미 노드들이다 -> false 반환
bool dfs(string s){
    if(s.size()==1){
        return (s == "1" ? true : false);
    }
    int root = s.size()/2;
    bool ch_le = dfs(s.substr(0, root));
    bool ch_ri = dfs(s.substr(root+1, s.size()));
    if(s[root]=='0'){
        if(ch_le || ch_ri) {
            ans = false;
        }
        else return false;
    }
    return true;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(long long n : numbers){
        string s = ""; ans = true;
        //이진수로 바꿈
        while(n){
            s = to_string(n%2) + s;
            n/=2;
        }
        make_fullbinarytree(s);
        dfs(s);
        answer.push_back(ans);
    }
    
    return answer;
}

/*
주어진 수를 이진수로 변환하고 포화 이진 트리의 사이즈만큼 0을 앞에 붙인다. (make_fullbinarytree 함수)
dfs 함수를 통해 하나의 이진 트리를 만들 수 있는지 확인한다. 
해당 함수는 트리가 더미노드들로 이루어져있으면 false, 아니면 true를 반환한다.
루트노드가 0인데(더미노드) 왼쪽 서브트리 혹은 오른쪽 서브트리가 존재한다면
하나의 이진트리로 만들 수 없다는 뜻이므로 답에 0을 답는다. 아니라면 만들 수 있으므로 1을 담는다.
*/