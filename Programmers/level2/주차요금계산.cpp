#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

map<string, vector<string>> m;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<string> car[1001];
    int cnt = 0;
    for(string s: records){
        stringstream ss;
        ss.str(s);
        string time, number, t = "";
        ss>>time; ss>>number;
        for(int i=0;i<time.size();i++) if(time[i]!=':') t+=time[i];
        m[number].push_back(t);
    }
    for(auto iter = m.begin(); iter!=m.end();iter++){
        int parking_time = 0;
        for(int i=0;i<m[iter->first].size();i+=2){
            int t1 = stoi(m[iter->first][i]);
            int mi1 = t1%100;
            if(i+1==m[iter->first].size()){
                int t2 = 2359;
                int mi2 = 59;
                if(59-mi1<0){
                    t2-=100;
                    mi2+=60;
                }
                parking_time += mi2-mi1+60*(t2/100 - t1/100);
            }
            else{
                int t2 =  stoi(m[iter->first][i+1]);
                int mi2 = t2%100;
                if(mi2-mi1<0){
                    t2-=100;
                    mi2+=60;
                }
                parking_time +=mi2-mi1+60*(t2/100 - t1/100);
            }
        }
        if(parking_time<=fees[0]) answer.push_back(fees[1]);
        else answer.push_back(fees[1] + ceil((double(parking_time)-fees[0])/fees[2])*fees[3]);
    }
    
    return answer;
}