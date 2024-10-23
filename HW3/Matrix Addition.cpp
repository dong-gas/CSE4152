#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    vector<vector<long double>> A(N + 2, vector<long double> (N + 2)), B(N + 2, vector<long double> (N + 2, 0.0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int r1, r2, c1, c2;
        long double v;
        cin >> r1 >> c1 >> r2 >> c2 >> v;
        B[r1][c1] += v;
        B[r2 + 1][c1] -= v;
        B[r1][c2 + 1] -= v;
        B[r2 + 1][c2 + 1] += v;
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) B[i][j] += B[i][j - 1];
    }
    for(int j = 1; j <= N; j++) {
        for(int i = 1; i <= N; i++) B[i][j] += B[i - 1][j]; 
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cout << fixed;
            cout.precision(12);
            cout << A[i][j] + B[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
