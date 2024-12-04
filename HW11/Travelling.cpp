#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> adj;
vector<vector<int>> dp;

int rec(int state, int u, int S) {
    if(state + 1 == 1 << n) return adj[u][S];
    int& ret = dp[state][u];
    if(ret != -1) return ret;
    ret = 1e9;
    for(int v = 0; v < n; v++) {
        if(state & (1 << v)) continue;
        ret = min(ret, rec(state | (1 << v), v, S) + adj[u][v]);
    }
    return ret;
}

int travelling(int N, const vector<vector<int>> &cost_graph) {
    adj = cost_graph;
    n = N;
    int answer = 1e9;

    // TODO: Implement the travelling function
    for(int i = 0; i < n; i++) {
        dp = vector<vector<int>> (1 << n, vector<int> (n, -1));
        answer = min(answer, rec(1 << i, i, i));
    }
    
    return answer;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> cost_graph(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cost_graph[i][j];
        }
    }

    int ans = travelling(N, cost_graph);
    cout << ans << '\n';

    return 0;
}
