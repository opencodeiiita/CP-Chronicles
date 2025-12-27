#include <bits/stdc++.h>
using namespace std;
/*
Logic:
The main key in solving the problem is that a,b will be enought to know that the size of the area.
Another observation would be that 1 is always facing the element  more than the element which faces 
at the last element or the size of the circle.
Once, you get the size of the array, we just have to check if the any of the elements are larger than 
the size of the array. 
On deeper checks like- a=3, b=2,c=1;
we can observe how this isn't true but how does the conditon fulfill the case?
--> the max check covers all small checks, like the circle don being possible
in cases like a=1,b=6, c=100
--> the circle condition is also checked by the max case. 

So, after the checking, we need to see the answer, that can be easily given as the
difference is same for all pairs of elements  modular nature of the circle( cool words that make sense)
 
Time complexity-->

The time complexity is O(1)
The space complexity is O(1)

Submission link- https://codeforces.com/contest/1560/submission/355188467
*/
//Soln->
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int a,b,c;
        cin>>a;
        cin>>b;
        cin>>c;
        int x=abs(b-a);
    if(max({a,b,c})>(2*x))
    cout<<-1<<endl;
    else
    {
        if(c>x)
        cout<<c-x<<endl;
        else
        cout<<c+x<<endl;
    }
    
    }
    return 0;
}
    
