#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<vector<int>> jda;
vector<int> dist;
int N, M;
string ret;
bool finish;

void dfs(int u) {
    if(finish) return;
    if(u == N + M) {
        finish = true;
        return;
    }
    for(auto [v, p]: adj[u]) if(dist[v] + 1 == dist[u] && !finish) {
        ret += p + '0';
        dfs(v);
    }
}


string Gifts(const string& d, int n, int m) { 
    vector<int> a;
    for(auto c: d) a.push_back(c - '0');
    adj = vector<vector<pair<int, int>>> (2 * n);
    jda = vector<vector<int>> (2 * n);
    dist = vector<int> (2 * n, 0);
    N = n, M = m;
    finish = false;
    ret = "";
    for(int i = 0; i < n; i++) {
        for(int p: a) {
            int j = 10 * i + p;
            if(j < n) {
                adj[i].push_back({j, p});
                jda[j].push_back(i);
            }
            else {
                adj[i].push_back({(j % n) + n, p});
                jda[(j % n) + n].push_back(i);
            }
        }
    }
    for(int i = n; i < 2 * n; i++) {
        for(int p: a) {
            int j = 10 * i + p;
            adj[i].push_back({(j % n) + n, p});
            jda[(j % n) + n].push_back(i);
        }
    }
    for(int i = 0; i < 2 * n; i++) sort(adj[i].begin(), adj[i].end(), [&] (pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
    queue<int> q;
    q.push(m + n);
    while(!q.empty()) {
        auto u = q.front(); q.pop();
        for(int v: jda[u]) if(!dist[v] && v != n + m) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    if(dist[0]) {
        dfs(0);
        return ret;
    }
    else return "IMPOSSIBLE";
}

int main() {
    ios_base::sync_with_stdio(0);
    int test_num;
    cin >> test_num;

    while (test_num--) {
        string d;
        int n, m;
        cin >> d >> n >> m;

        cout << Gifts(d, n, m) << "\n";
    }

    return 0;
}
