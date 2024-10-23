#include <bits/stdc++.h>
using namespace std;

vector<int> findNLargestElements(vector<vector<int>>& a, int n) {
    vector<int> largestElements;
    // TODO:
    vector<int> cnt(n, 0);
    for(int i = 0; i < n; i++) {
        int idx = -1, maxi = -1e9;
        for(int j = 0; j < n; j++) {
            if(a[i][j] > maxi) {
                maxi = a[i][j];
                idx = j;
            }
        }
        swap(a[i][idx], a[i][n - 1]);
    }

    while(largestElements.size() < n) {
        int ridx = -1, maxi = -1e9;
        for(int i = 0; i < n; i++) {
            int rm = a[i][n - 1 - cnt[i]];
            if(rm > maxi) {
                ridx = i;
                maxi = rm;
            }
        }
        largestElements.push_back(maxi);
        
        int nidx = 0, nmaxi = -1e9;
        for(int j = 0; j < n - 1 - cnt[ridx]; j++) {
            if(a[ridx][j] > nmaxi) {
                nmaxi = a[ridx][j];
                nidx = j;
            }
        }
        if(++cnt[ridx] < n) swap(a[ridx][n - 1 - cnt[ridx]], a[ridx][nidx]);
    }
    
    
    return largestElements;
}

int main() {
    // Do NOT delete these lines unless you know what you are doing:
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> M(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> M[i][j];
        }
    }

    vector<int> largestElements = findNLargestElements(M, n);

    for (int element : largestElements) {
        cout << element << "\n";
    }

    return 0;
}
