#include <bits/stdc++.h>

using namespace std;
/**
 * @brief Asks person A if they know person B.
 * @param a The number of person A.
 * @param b The number of person B.
 * @return true if A knows B, otherwise returns false.
 */
bool ask_a_to_know_b(int a, int b) {
    int result;
    std::cout << "? " << a << ' ' << b << std::endl;
    std::cin >> result;
    assert(result == 0 || result == 1);
    return result;
}

/**
 * @brief Verifies if person x is a celebrity.
 * @param x The number of the person to verify, or -1 if there is no celebrity.
 * @return true if the answer is correct, otherwise returns false.
 */
bool answer(int x) {
    int result;
    std::cout << "! " << x << std::endl;
    std::cin >> result;
    assert(result == 0 || result == 1);
    return result;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    int now = 1;
    vector<vector<array<int, 3>>> a(n + 1);
    for(int i = 2; i <= n; i++) {
        int query = ask_a_to_know_b(now, i);
        if(query) {
            a[i].push_back({now, i, 1});
            now = i;
        }
        else a[now].push_back({now, i, 0});
    }
    vector<vector<int>> chk(n + 1, vector<int> (2, -1));
    for(auto& [i, j, q]: a[now]) {
        if(i == now) {
           chk[j][0] = q; 
           if(q == 1) {
               answer(-1);
               return 0;
           }
        }
        else {
            chk[i][1] = q;
            if(q == 0) {
                answer(-1);
                return 0;
            }
        }
        
    }
    for(int i = 1; i <= n; i++) {
        if(i == now) continue;
        if(chk[i][0] == -1) chk[i][0] = ask_a_to_know_b(now, i);
        if(chk[i][0]) {
            answer(-1);
            return 0;
        }
        if(chk[i][1] == -1) chk[i][1] = ask_a_to_know_b(i, now);
        if(!chk[i][1]) {
            answer(-1);
            return 0;
        }
    }
    //for(int i = 1; i <= 1000000000; i++) i = i;
    answer(now);
    // TODO: write your logic here!
    // You can use the functions `ask_a_to_know_b` and `answer`.
    // Any invocation of print functions rather than `ask_a_to_know_b`
    // and `answer` will result in 0 points for this question.
    return 0;
}
