#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
int n;

int main(void) {
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (v.empty()) v.push_back(a);
        else {
            if (v.back() < a) {
                v.push_back(a);
            }
            else {
                int it = lower_bound(v.begin(), v.end(), a) - v.begin();
                v[it] = a;
            }
        }
    }
    cout << v.size();

    return 0;
}