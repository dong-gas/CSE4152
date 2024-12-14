#include <bits/stdc++.h>

using namespace std;

vector<int> pebbles(int n, int k, string s) {
    s = " " + s;
    vector<int> ans, pre(n + 2, 0);
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + ((s[i] == 'W') ? 1 : 0);
    pre[n + 1] = 1e9;
    int l = 1, r = 1, ansl = 0, ansr = 0;
    while (r <= n) {      
        if(r - l + 1 > ansr - ansl + 1) ansl = l, ansr = r;
        if(pre[r + 1] - pre[l - 1] <= k) r++;
        else l++;
    }
    for(int i = ansl; i <= ansr; i++) if(s[i] == 'W') ans.push_back(i);
    return ans;
}

int main() {
    int N, K;
    string S;

    cin >> N >> K >> S;

    vector<int> ans = pebbles(N, K, S);

    cout << ans.size() << '\n';
    for (int x: ans) cout << x << ' ';
    cout << '\n';

    return 0;
}
