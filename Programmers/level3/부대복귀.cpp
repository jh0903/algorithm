//destination에서 bfs를 진행시키면 각 정점에서 destination까지의 최소 거리를 구할 수 있다.
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> adj[100005];
int dist[100005];
queue<pair<int,int>> q;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    //인접 리스트 만들기
    int si = roads.size();
    for(int i=0;i<si;i++){
        adj[roads[i][0]].push_back(roads[i][1]);
        adj[roads[i][1]].push_back(roads[i][0]);
    }
    //dist[]: destination에서 각 정점까지의 최소 거리. -1로 초기화(방문하지 않은 상태를 의미함)
    for(int i=1;i<=n;i++) dist[i] = -1;

    //destination에서 시작하는 bfs
    q.push({destination, 0});
    dist[destination] = 0;
    while(!q.empty()){
        int cur_v = q.front().first;
        int cur_dist = q.front().second; q.pop();
        for(int nxt: adj[cur_v]){
            if(dist[nxt] != -1) continue;   
            dist[nxt] = cur_dist + 1;
            q.push({nxt, dist[nxt]});
        }
    }
    
    //답 담기
    for(int v : sources){
        answer.push_back(dist[v]);
    }
    return answer;
}