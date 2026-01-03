// submission: https://codeforces.com/contest/1777/submission/356260631

/* Given n students of a school and m topics 1,2,3,…,m from which the quiz questions will be formed. 
The i-th student is considered proficient in a topic T if (ai%T)=0.
Otherwise, he is a rookie in that topic. We are asked to find the team formation of any no. of students 
such that for every topic there is a member of the team proficient in this topic. Whilst minimizing the 
maximum difference between the smartness of any two students and output this difference */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7; // 998244353
const ll INF = 1e18;
const int maxval=100005;
vector<int> divisors[maxval];

void precompute(){
    for(int i=1;i<maxval;i++){
        for(int j=i;j<maxval;j+=i) divisors[j].push_back(i);
    }
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(auto &x: a) cin>>x;
    sort(all(a));
    int cov_topics=0, min_dif=INT_MAX, l=0;//left
    vector<int> cnt(m+1,0);

    //we take 2 pointers left and right
    for(int r=0;r<n;r++){
        // Add current student's topics to the window
        for(int topic: divisors[a[r]]){
            if(topic>m) break; //since divisors[] also keeps sorted divisors, if one is greater than m, then all subsequent will be so
            if(cnt[topic]==0) cov_topics++; //increment cov_topics for every unique topic
            cnt[topic]++;
        }

        /* While covered_topics == m (i.e., the team is valid): 
            Update the minimum difference: ans = min(ans, a[right] - a[left]).
            Move the left pointer forward to try and shrink the window. 
            Remove the left student's factors from the count.*/
        while(cov_topics==m){
            min_dif=min(min_dif,a[r]-a[l]);
            for(int topic: divisors[a[l]]){
                if(topic>m) break;
                cnt[topic]--;
                if(cnt[topic]==0) cov_topics--;
            }
            l++;
        }
    }
    if(min_dif==INT_MAX) cout<<-1<<endl; //means no team can cover all the m topics
    else cout<<min_dif<<endl;

}

int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
