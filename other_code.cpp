#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

#define int long long

signed main() {
    long long n, a;
    cin >> n >> a;
    if (a == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 2) {
        if (a == 2) {
            cout << 2 << endl;
        }
        return 0;
    }
    if (n == 3) {
        if (a == 2) {
            cout << 3 << endl;
        }
        if (a == 3) {
            cout << 4 << endl;
        }
        return 0;
    }
    vector<double> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1; // 1 1

    for (int i = 2; i <= a; ++i) {
        dp[i] = dp[i - 1] * 2;
    }
    for (int i = a + 1; i <= n; ++i) {
        for (int j = 1; j <= a; ++j) {
            dp[i] += dp[i - j];
        }
    }

    cout << fixed << dp[n] << "\n";
    // cout << dp[n] << endl;
    return 0;
}
