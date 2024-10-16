#include <bits/stdc++.h>

using namespace std;

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

        double max_dist = 0;

        vector<vector<pair<int, double>>> adj(n + 1);

        // input edge info
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            double w;
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        
        // TODO
        vector<double> d(n + 1, -1);
        int x = 1, y = 1;
        double ud = 0.0;
        function<void(int, int, double)> go = [&] (int u, int p, double ds) -> void {
            if(ds > ud) {
                ud = ds;
                x = u;
                y = u;
            }
            for(auto& [v, w]: adj[u]) {
                if(v == p) continue;
                go(v, u, ds + w);
            }
        };
        go(1, 0, 0.0);
        go(x, 0, 0.0);
        max_dist = ud / 2;
        // Print the minimum possible maximum distance
        cout << max_dist << "\n";
    }

    return 0;
}
