#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int cnt;

int dfs(int u, int p) {
    visited[u] = true;
    vector<int> v;
    v.push_back(0), v.push_back(0);
    for(int nxt: adj[u]) {
        if(nxt == p || visited[nxt]) continue;
        v.push_back(dfs(nxt, u) + 1);
    }
    sort(v.begin(), v.end(), greater<>());
    int i = 0;
    while(i + 1 < v.size() && v[i] + v[i + 1] > 2) i++, cnt++;
    return v[i];
}
 
int solve(int n) {
	int answer = 0;
    visited = vector<bool> (n, false);
	for(int i = 0; i < n; i++) {
        if(visited[i]) continue;
        cnt = 0;
        dfs(i, -1);
        answer += cnt + 1;
    }
	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int C, H, G, p1, p2;
	cin >> C;

	while (C--) {
		cin >> G >> H;
		adj = vector<vector<int>>(G);

		for (int i = 0; i < H; i++) {
			cin >> p1 >> p2;
			adj[p1].push_back(p2);
			adj[p2].push_back(p1);
		}

		cout << solve(G) << endl;
	}

	return 0;
}
