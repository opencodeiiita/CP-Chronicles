#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        int half=abs(b-a);
        int full=2*half;
        // cout<<full<<endl;
        if(a>full || b> full || c > full)
        {
            cout<<-1<<endl;
        }
        else
        {
            int ans=c+half;
            if(ans>full)
            {
                ans-=full;
            }
            cout<<ans<<endl;
        }
        
    }
    
}
