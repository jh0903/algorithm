#include <vector>
using namespace std;

int le[1000001], ri[1000001];

int solution(vector<int> a) {
    int answer = 0;
    int n = a.size();
    int mi = a[0];
    for(int i=0;i<n;i++){
        if(mi>a[i]) mi = a[i];
        le[i] = mi;
    }
    mi = a[n-1];
    for(int i=n-1;i>=0;i--){
        if(mi>a[i]) mi = a[i];
        ri[i] = mi;
    }
    for(int i=0;i<n;i++){
        if(!i||i==n-1){
            answer++;
            continue;
        }
        if(le[i-1]>a[i] || a[i]<ri[i+1]) answer++;
    }
    
    return answer;
}