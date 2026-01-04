/*
DAY 8
Q2 Enemy Is Weak

*/
/*


For each position j (as middle element), count how many elements on its left are greater than a[j] and how many on its right are smaller than a[j]. Multiply these two counts - this gives triplets with j as middle. Sum this for all positions.
Use Fenwick Tree (BIT) to efficiently count elements in ranges. Since values go up to 10^9, compress them to 1..n first. Two passes: left-to-right for greater left counts, right-to-left for smaller right counts.

*/
#include <bits/stdc++.h>
using namespace std;

int ft[1000005];
int n;

void upd(int idx, int val){
    for(; idx<=n; idx+=idx&-idx)
        ft[idx]+=val;
}

int qry(int idx){
    int ans=0;
    for(; idx>0; idx-=idx&-idx)
        ans+=ft[idx];
    return ans;
}

int main(){
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    
    // compress coordinates 
    vector<int> sorted_vals=a;
    sort(sorted_vals.begin(),sorted_vals.end());
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[sorted_vals[i]]=i+1;
    }
    
    vector<int> compressed(n);
    for(int i=0;i<n;i++){
        compressed[i]=mp[a[i]];
    }
    
    vector<long long> left_cnt(n), right_cnt(n);
    
    // left pass
    memset(ft,0,sizeof(ft));
    for(int i=0;i<n;i++){
        int pos=compressed[i];
        left_cnt[i]=qry(n)-qry(pos);
        upd(pos,1);
    }
    
    // right pass
    memset(ft,0,sizeof(ft));
    for(int i=n-1;i>=0;i--){
        int pos=compressed[i];
        right_cnt[i]=qry(pos-1);
        upd(pos,1);
    }
    
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=left_cnt[i]*right_cnt[i];
    }
    
    cout<<ans<<"\n";
    
    return 0;
}

//Tc =O(nlogn) per test  SC = O(n)
/*
My submission : https://codeforces.com/contest/61/submission/356391525
*/