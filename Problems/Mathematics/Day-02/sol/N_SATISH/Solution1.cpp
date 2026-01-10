#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int ti;
    cin >> ti;
    
    while(ti--) 
    {
        int kl;
        cin >> kl;
        
        vector<int> g(kl);
        for(int i = 0; i < kl; i++) 
        {
            cin >> g[i];
        }
        
        int m = *max_element(g.begin(), g.end());
        int n = *min_element(g.begin(), g.end());
        
        if(m == n) 
        
        {
            cout << (long long)kl * (kl - 1) << endl;
        }
        else 
        {
            long long cm = count(g.begin(), g.end(), m);
            long long cn = count(g.begin(), g.end(), n);
            cout << cm * cn * 2 << endl;
        }
    }
    
    return 0;
}