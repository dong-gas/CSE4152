#include <bits/stdc++.h>

using namespace std;
using ld = long double;

/*
  One Fire Station에서 사용했던 함수 다시 쓰려고 하다보니 코드가 안 이쁩니다.
  코드 말고 그냥 보고서 내용 보고 직접 짜는 게 깔끔할 듯..!
*/

int main() {
    // Do NOT delete these lines unless you know what you are doing:
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(12);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        ld max_dist = 0;

        vector<vector<pair<int, ld>>> adj(n + 1);
        vector<int> ind(n + 1);
        // input edge info
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            ld w;
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
            ind[u]++, ind[v]++;
        }
        
        // TODO
        int x = -1, y = - 1;
        bool t = false;
        ld ud = 0.0;
        function<void(int, int, ld)> go = [&] (int u, int p, ld ds) -> void {
            if(ds > ud) {
                ud = ds;
                if(!t) x = u;
                else y = u;
            }
            for(auto& [v, w]: adj[u]) {
                if(v == p) continue;
                go(v, u, ds + w);
            }
        };
        go(1, 0, 0.0);
        t ^= 1, ud = 0.0;
        go(x, 0, 0.0);
        vector<ld> dx(n + 1), dy(n + 1);
        function<void(int, int, ld, vector<ld>& )> dfs = [&] (int u, int p, ld ds, vector<ld>& dist) -> void {
            dist[u] = ds;
            for(auto& [v, w]: adj[u]) {
                if(v == p) continue;
                dfs(v, u, ds + w, dist);
            }
        };
        
        dfs(x, 0, 0.0, dx);
        dfs(y, 0, 0.0, dy);
        ld p = 0.0, q = 0.0;
        for(int i = 1; i <= n; i++) {  
            if(ind[i] > 1) continue;
            if(dx[i] <= dy[i]) p = max(p, dx[i]);
            else q = max(q, dy[i]);
        }
        cout << max(p, q) / 2 << "\n";
    }

    return 0;
}
