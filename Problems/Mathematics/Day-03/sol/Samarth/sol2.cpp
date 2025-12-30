#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

/*
PROBLEM STATEMENT:
Mad scientist Mike is building a time machine in his spare time. To finish the work, he needs a resistor with a certain resistance value.

However, all Mike has is lots of identical resistors with unit resistance [ R 0 = 1 ] . Elements with other resistance can be constructed from these resistors. In this problem, we will consider the following as elements:

    one resistor;
    an element and one resistor plugged in sequence;
    an element and one resistor plugged in parallel.

With the consecutive (series) connection the resistance of the new element equals

[ R = R e + R 0 . ]

With the parallel connection the resistance of the new element equals

[ R = R e ⋅ R 0 R e + R 0 . ]

In these formulas, ( R e ) denotes the resistance of the element being connected.

Mike needs to assemble an element with a resistance equal to the fraction ( a b ) . Determine the smallest possible number of resistors he needs to make such an element.


APPROACH:
Well i knew at glance the approach for a>b that would be a/b series resistors but i was stuck for a sol for a<b then i got the hint from tutorial and it clicked
me that this problem is similar to backtracking we do in ques like counting min coins needed to make a denomination (1,3,5 rs) so similar to that i knew backtracking for a>b;
but a<b i realised this would be pretty similar just you have to take parallel before that (the choices in each step can be SPSPSS...something like that)
so you can take condtion b>a as just opposite of a solve(a,b%a,count) also i passed counter as a reference to track no. of resistors. and when looking  
closely you can see this is nothing but the procces we follow while calculating gcd of (a,b) i did know the process but i did not know the name was Eucledian Algo 
also i didnt know the time complexity of that.

TIME COMPLEXITY: for a eucledian algo it is (log(min(a,b)));

SUBMISSION LINK: 
https://codeforces.com/contest/343/submission/355701892

*/



ll solve(ll a,ll b,ll &count){
	if(a==1)return count+b;
	if(b==1)return count+a;
	if(a>=b){
		count+=a/b;
		return solve(a%b,b,count);
	}
	else{
		count+=b/a;
		return solve(a,b%a,count);
	}
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	ll a,b;cin>>a>>b;ll count=0;
	cout<<solve(a,b,count)<<endl;

	
}
