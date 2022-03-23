#include<iostream>
using namespace std;

int arr[1001], dp1[1001], dp2[1001], ans;

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dp1[0] = 1;
    for (int i = 1; i < n; i++) {
        dp1[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[i] > arr[j])
                dp1[i] = max(dp1[i], dp1[j] + 1);
        }
    }
    dp2[0] = 1;
    for (int i = n - 1; i >= 0; i--) {
        dp2[i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j])
                dp2[i] = max(dp2[i], dp2[j] + 1);
        }
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }
    cout << ans;

    return 0;
}