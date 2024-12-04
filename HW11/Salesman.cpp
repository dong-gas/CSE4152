#include <bits/stdc++.h>

using namespace std;
using pint = pair<int, int>;

vector<pint> salesman(int n, vector<pint> v) {
    vector<pint> answer;
    
    // TODO: Implement the salesman function
    sort(v.begin(), v.end(), [&](pint x, pint y) {
        return x.second < y.second;
    });
    int end = 0;
    for(auto& [l, r]: v) {
        if(end <= l) {
            answer.push_back({l,r});
            end = r;
        }
    }
    return answer;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, int>> meetings(N);

    for (int i = 0; i < N; i++) {
        cin >> meetings[i].first >> meetings[i].second;
    }

    vector<pair<int, int>> ans = salesman(N, meetings);

    for (auto meeting: ans) {
        cout << meeting.first << " " << meeting.second << " ";
    }
    cout << '\n';

    return 0;
}
