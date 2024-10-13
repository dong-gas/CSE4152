#include <bits/stdc++.h>

using namespace std;

struct point {
    double x, y;

    point() : x(0), y(0) {}

    point(double x, double y) : x(x), y(y) {}
};

int f(point a) { //사분면 판독기
    if(a.x > 0 && a.y >= 0) return 1;
    if(a.x <= 0 && a.y > 0) return 2;
    if(a.x < 0 && a.y <= 0) return 3;
    if(a.x >= 0 && a.y < 0) return 4;
    return 0; 
}

bool half_circle_property(int n, vector<point>& v) {
    //only 3사분면 기준으로 풀자.
    vector<bool> chk(5, 0);
    //
    point m = point(-1e9, -1e9), M = point(1e9, 1e9), a = M , A = m, c = M, C = m;
    for(int i = 0; i < n; i++) {
        auto [x, y] = v[i];
        int k = f(v[i]);
        if(k == 1) {
            if(x < a.x) a = v[i];
            if(x > A.x) A = v[i];
        }
        if(k == 3) {
            if(x < c.x) c = v[i];
            if(x > C.x) C = v[i];
        }
        chk[k] = 1;
    }
    if(!chk[3] || !chk[1]) {
        if(!chk[2] || !chk[4]) return true;
        return false;
    }

    if(-c.x <= a.x && !chk[2]) return true;
    if(-C.x >= A.x && !chk[4]) return true;


    return false;
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

        vector<point> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i].x >> A[i].y;
        }

        bool answer = false;
        for(int cnt = 0; cnt < 4; cnt++) {
            answer |= half_circle_property(N, A);
            for(int i = 0; i < N; i++) {
                double p = -A[i].y, q = A[i].x;
                A[i] = point(p, q);
            }
        }
        cout << answer << '\n';
    }

    return 0;
}
