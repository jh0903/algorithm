#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int> pq;

int solution(int n, int k, vector<int> enemy) {
    int sum = 0, answer = 0;
    for(int x : enemy){
        pq.push(x);
        sum += x;
        if(sum > n){
            if(k) {
                sum -= pq.top(); pq.pop();
                k--;
            } else break;
        }
        answer++;
    }
    return answer;
}

/*
1라운드부터 시작해서 최대한 많은 라운드를 올라가야 하는 문제
1부터 ?라운드까지 가장 많은 적이 등장하는 k개의 라운드에 무적권 스킬을 쓰면 된다.
-> 우선순위 큐를 활용해 최댓값을 관리하면 된다.
enemy의 길이를 n이라 하면, 시간복잡도: nlog(n)
최대 100만까지 주어지므로 시간 내에 풀 수 있다.
*/