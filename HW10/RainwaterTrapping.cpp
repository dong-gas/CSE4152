#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int maxWater(vector<int>& arr) {
    ll n = arr.size(), res = 0;
    vector<ll> a(n + 2, 0), pre(n + 2, 0), suf(n + 2, 0);
    for(int i = 1; i <= n; i++) a[i] = arr[i - 1], pre[i] = max(pre[i - 1], a[i]);
    for(int i = n; i >= 1; i--) suf[i] = max(suf[i + 1], a[i]), res += max((min(pre[i - 1], suf[i + 1]) - a[i]), 0ll);
    return res;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test_num;
    cin >> test_num; 

    for (int t = 0; t < test_num; ++t) {
        int B;
        cin >> B; 

        vector<int> arr(B);
        for (int i = 0; i < B; ++i) {
            cin >> arr[i];
        }

        cout << maxWater(arr) << endl;
    }

    return 0;
}
