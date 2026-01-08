#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];
    vector<int> u(N), v(N);
    for(int i=0; i<N; ++i) {
        u[i] = min(A[i], B[i]);
        v[i] = max(A[i], B[i]);
    }
    vector<int> dp(N);
    long long total_pairs = 0;
    
    int chunk_start = 0;
    while(chunk_start < N) {
        int chunk_end = chunk_start;
        while(chunk_end < N - 1) {
            if (u[chunk_end] > v[chunk_end+1]) {
                break;
            }
            chunk_end++;
        }
        dp[chunk_end] = chunk_end;
        int nxt_R = N + 1; 
        int nxt_HD = N + 1; 
        for (int k = chunk_end - 1; k >= chunk_start; --k) {
            bool is_FH = (u[k] > u[k+1]); 
            if (is_FH) {
                int limit_H = nxt_HD;
                int limit_Q = nxt_R;
                if (limit_H < limit_Q) {
                    dp[k] = limit_H;
                } else {
                    if (limit_Q > chunk_end) {
                        dp[k] = chunk_end;
                    } else {
                        dp[k] = dp[limit_Q + 1];
                    }
                }
            } else {
                dp[k] = dp[k+1];
            }
            bool is_R = (v[k] < u[k+1]);
            bool is_HD = (v[k] > v[k+1]);
            if (is_R) nxt_R = k;
            if (is_HD) nxt_HD = k;
        }
        for (int i = chunk_start; i <= chunk_end; ++i) {
            total_pairs += (long long)(dp[i] - i + 1);
        }
        chunk_start = chunk_end + 1;
    }
    cout << total_pairs << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while(T--) {
            solve();
        }
    }
    return 0;
}