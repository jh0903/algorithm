#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool check(string &s, string &friends){
    int diff = friends.find(s[0]) - friends.find(s[2]);
    diff = abs(diff);
    if(s[3]=='>' && diff > s[4]-'0' + 1) return true;
    else if(s[3]=='<' && diff <= s[4]-'0') return true;
    else if(s[3]=='=' && diff == (s[4]-'0' + 1)) return true;
    return false;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";
    do{
        bool flag = true;
        for(string s: data){
            if(!check(s, friends)) {
                flag = false;
                break;
            }
        }
        if(flag) answer++;
    }while(next_permutation(friends.begin(), friends.end()));
    
    return answer;
}