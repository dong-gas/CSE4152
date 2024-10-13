#include <bits/stdc++.h>

using namespace std;

bool can_rearrange_trains(int N, vector<int> &trains) {
    // TODO:
    stack<int> st, tmp;
    for(int i=N-1;i>=0;i--) st.push(trains[i]);
    vector<int> chk(N+1,0);
    for(int now=1;now<=N;now++) {
        if(chk[now]) {
            if(tmp.top()==now) {
                tmp.pop();
            }
            else return false;
        }
        else {
            while(st.top()!=now) {
                chk[st.top()]=1;
                tmp.push(st.top());
                st.pop();
            }
            if(st.empty()) return false;
            else if(st.top()==now) {
                st.pop();
            }
        }
    }
    return true;
}

int main() {
    // Do NOT delete these lines unless you know what you are doing:
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> trains(N);
        for (int i = 0; i < N; i++) {
            cin >> trains[i];
        }

        cout << can_rearrange_trains(N, trains) << '\n';
    }

    return 0;
}
