/*
보고서와 다르게 2회 이동으로 푸는 풀이
*/

#include <bits/stdc++.h>
#include "env.h"

using namespace std;

int n;

void solve() {
    cin >> n;
    vector<int> dap(n, -1);
    vector<int> lred(n, -1);
    vector<int> lblue = lred, rred = lred, rblue = lred;
    for(int i = 2; i < n; i += 2) {
        link_wire(i - 1, i);
        lblue[i - 1] = i;
        lblue[i] = i - 1;
    }
    move_to_opposite();
    deque<int> v;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(!check_connectivity(i, j)) continue;
            rblue[i] = j;
            rblue[j] = i;
            v.push_back(i);
            v.push_back(j);
        }
    }
    for(int i = 0; i < n; i++) {
        if(rblue[i] == -1) {
            if(v.size() < n - 1 || n & 1) v.push_front(i);
            else v.push_back(i);
        }
    }
    //for(int i: v) cout << i << ' ';
    //cout << endl;
    for(int i = 1; i < n - 1; i += 2) {
        link_wire(v[i - 1], v[i]);
        rred[v[i - 1]] = v[i];
        rred[v[i]] = v[i - 1];
    }
    move_to_opposite();
    clean_wires();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(!check_connectivity(i, j)) continue;
            lred[i] = j;
            lred[j] = i;
        }
    }
    int re = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(lred[i] != -1 || lblue[i] != -1 || rred[j] != -1 || rblue[j] != -1) continue;
            //cout << "남는애 : " << i << ' ' << j << endl;
            dap[i] = j;
            if(i == 0) re = n - 1;
        }
    }
    for(int j = 0; j < n; j++) {
        if(rblue[j] == -1 && rred[j] != -1) dap[re] = j;
    }
    //cout<<"dap[0]: "<<dap[0]<<endl;
    int l = re, r = dap[re];

    //for(int i = 0; i < n; i++) cout << lblue[i] << ' ' << lred[i] << endl;
    //for(int i = 0; i < n; i++) cout << rblue[i] << ' ' << rred[i] << endl;

    //cout << l << ' ' << r << endl;
    bool red = 1;
    for(int cnt = 0; cnt < n - 1 - (n & 1 ? 0 : 1); cnt++, red ^= 1) {
        if(red) {
            l = lred[l], r = rred[r];
            dap[l] = r;
        }
        else {
            l = lblue[l], r= rblue[r];
            dap[l] = r;
        }
        //cout << l << ' ' << r << '\n';
    }
    vector<pair<int, int>> res;
    for(int i = 0; i < n; i++) res.push_back({i, dap[i]});
    answer(res);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
