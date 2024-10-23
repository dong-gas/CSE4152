#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, x, ans;

int main() {
    cin >> n;
    vector<ll> dp(n + 1, 0);
    for(ll i = 1; i <= n; i++) {
        cin >> x;
        dp[i] = max(dp[i-1] + x, x);
        dp[i] = max(dp[i], 0ll);
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}
