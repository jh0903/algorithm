#include <string>
#include <map>
#include <vector>
using namespace std;

map<char, int> mp;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int si = survey.size();
    for(int i=0;i<si;i++){
        if(choices[i]<4) mp[survey[i][0]]+=(4 - choices[i]);
        else if(choices[i]>4) mp[survey[i][1]] += (choices[i]-4);
    }
    if(mp['R']>=mp['T']) answer+='R';
    else answer+='T';
    if(mp['C']>=mp['F']) answer+='C';
    else answer+='F';
    if(mp['J']>=mp['M']) answer+='J';
    else answer+='M';
    if(mp['A']>=mp['N']) answer+='A';
    else answer+='N';
    
    return answer;
}