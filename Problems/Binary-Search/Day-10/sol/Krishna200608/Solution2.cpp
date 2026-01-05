/*
1) Submission Link: https://www.codechef.com/viewsolution/1223475549
2) Problem: Perfect Ranges (PERRANGES)
   Link: https://www.codechef.com/problems/PERRANGES
   Author: Krishna200608

3) Short Problem Statement:
   Given two arrays A and B of size N. A range [L, R] is perfect if we can pick
   one element from A[i] or B[i] for each i in range, such that the selected
   sequence is strictly increasing. Count valid pairs (L, R).

/*
4) Approach (humanized & short):
    For each adjacent index i -> i+1, build a 2x2 boolean matrix that represents valid transitions between choosing A or B at i to choosing A or B at i+1 while keeping the sequence strictly increasing.

    A range [L, R] is valid if the matrix product M[L] * M[L+1]*..* M[R-1] is not a zero matrix, meaning at least one increasing sequence is possible.
    Use a sliding window over R and try to keep the left pointer L as small as possible while the range stays valid.
    Maintain the matrix product of the current window using SWAG (two stacks), which allows amortized O(1) push (extend R) and pop (shrink L).
    If the window becomes invalid, move L forward until it becomes valid again.
    For each R, all ranges [L, R], [L+1, R], ..., [R, R] are valid, so add (R - L + 1) to the answer.


5) Time & Space Complexity:
   Time:   O(N)
   Space: O(N) 
*/

#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
const int M = 1e9+7;
const double PI = acos(-1.0);
#define INF 1e18
#define pb push_back
#define ppb pop_back
#define ll long long
#define no cout << "NO" << endl;
#define yes cout << "YES" << endl;
#define ff first
#define ss second
#define inn(x) int x; std::cin >> x;
#define ill(x) ll x; std::cin >> x;
#define all(x) x.begin(),x.end()
#define in(a) for(int i = 0; i<a.size(); i++) cin>>a[i];
#define out(a) for(int i = 0; i<a.size(); i++) cout<<a[i]<< " " ;
typedef vector<int> vi;
typedef vector<ll> vll;
#define ceil_div(n, x)  ( ((n) % (x) == 0) ? ((n) / (x)) : ((n) / (x) + 1) )
#define debug(x) cout << "x -> " << x << endl;
#define outt(x) cout << x << endl;
#define endl "\n"

struct Mat {
    bool m[2][2];
    Mat() {
        memset(m, 0, sizeof(m));
    }
    static Mat id() {
        Mat res;
        res.m[0][0] = res.m[1][1] = 1;
        return res;
    }
    friend Mat operator*(const Mat &A, const Mat &B) {
        Mat res;
        for(int i=0; i<2; ++i) {
            for(int k=0; k<2; ++k) {
                if(A.m[i][k]) {
                    for(int j=0; j<2; ++j) {
                        if(B.m[k][j]) res.m[i][j] = 1;
                    }
                }
            }
        }
        return res;
    }
    bool any() {
        return m[0][0] || m[0][1] || m[1][0] || m[1][1];
    }
};

vector<pair<Mat, Mat>> stL, stR;

void push_R(Mat x) {
    Mat cur = x;
    if(!stR.empty()) cur = stR.back().ss * x;
    stR.pb({x, cur});
}

void pop_L() {
    if(stL.empty()) {
        while(!stR.empty()) {
            Mat val = stR.back().ff;
            stR.ppb();
            Mat cur = val;
            if(!stL.empty()) cur = val * stL.back().ss;
            stL.pb({val, cur});
        }
    }
    stL.ppb();
}

bool check() {
    if(stL.empty() && stR.empty()) return true;
    Mat res;
    if(stL.empty()) res = stR.back().ss;
    else if(stR.empty()) res = stL.back().ss;
    else res = stL.back().ss * stR.back().ss;
    return res.any();
}

void solve(){
    inn(n);
    vll a(n), b(n);
    in(a);
    in(b);
    stL.clear();
    stR.clear();
    vector<Mat> mats(n);
    for(int i=0; i<n-1; ++i) {
        mats[i].m[0][0] = (a[i] < a[i+1]);
        mats[i].m[0][1] = (a[i] < b[i+1]);
        mats[i].m[1][0] = (b[i] < a[i+1]);
        mats[i].m[1][1] = (b[i] < b[i+1]);
    }
    ll ans = 0;
    int L = 0;
    for(int R = 0; R < n; ++R) {
        if(R > 0) {
            push_R(mats[R-1]);
        }
        while(L < R && !check()) {
            pop_L();
            L++;
        }
        ans += (ll)(R - L + 1);
    }
    outt(ans);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    auto begin = std::chrono::high_resolution_clock::now();
    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-6 << "ms";
    return 0;
}
