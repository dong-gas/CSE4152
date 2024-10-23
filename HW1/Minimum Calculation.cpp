#include <bits/stdc++.h>

using namespace std;
typedef bitset<2001> bs;
typedef tuple<int, int, bs> t;

struct cmp {
    bool operator()(t x, t y) {
        if(get<0>(x) == get<0>(y)) {
            if(get<1>(x) == get<1>(y)) return false;
            return get<1>(x) < get<1>(y);
        }
        return get<0>(x) < get<0>(y);
    }
};

vector<int> min_multiplications(int n) {
    vector<int> powers, visited(n + 1, 0);
    priority_queue<t, vector<t>, cmp> q;
    bs s;
    s.set(1,1);
    t x = make_tuple(-1, 1, s);
    visited[1] = 1;
    q.push(x);
    while(!q.empty()) {
        t now = q.top(); q.pop();
        auto [d, u, b] = now;
        d = -d;
        if(visited[u] < d) continue;
        if(u == n) {
            for(int i = 1; i <= n; i++) if(b[i]) powers.push_back(i);
            return powers;
        }
        for(int i = u; i >= 1; i--) {
            if(!b[i] || u + i > n || (visited[u + i] < d + 1 && visited[u + i] > 0)) continue;
            b[u + i] = 1;
            q.push(make_tuple(-(d + 1), u + i, b));
            visited[u + i] = d + 1;
            b[u + i] = 0;
        }
    }   
    return powers;
}

int main(){
    int n;
    cin >> n;
    vector<int> steps = min_multiplications(n);
    cout << (int)steps.size() - 1 << ' ';
    for (int& step : steps) cout << step << ' ';
    
    return 0;
}
