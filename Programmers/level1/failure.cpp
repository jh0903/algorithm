#include <string>
#include <vector>
#include <algorithm>
using namespace std;

double challenge[501], fail[501];
bool cmp(pair<double, int> a, pair<double, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int si = stages.size();
    for (int i = 0; i < si; i++) {
        for (int j = 1; j <= stages[i]; j++) {
            challenge[j]++;
        }
        fail[stages[i]]++;
    }
    vector<pair<double, int>> v;
    for (int i = 1; i <= N; i++) {
        if(!challenge[i]) v.push_back({0,i});
        else v.push_back({ fail[i] / challenge[i], i });
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < N; i++) answer.push_back(v[i].second);
    return answer;
}