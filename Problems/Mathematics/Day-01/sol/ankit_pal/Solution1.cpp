/* https://codeforces.com/contest/1560/submission/355289291
PROBLEM STATEMENT: To find who is opposite to c after knowing the positions of a and b who are diametrically opposite to each other in a circle having 
even no. of people*/

//T.C. :O(t)
//S.C. :O(1)

#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
	long long t, a, b, c, total;
	cin >> t;   //no. of test cases
	
	while(t--){     
	    cin >> a >> b >> c;
	    
	    total = 2*abs(b-a); /*determining total no. of people in circle logic: a and b are diametrically opposite, 2*((no. of
                          people between a and b) + 1) = total no. of people in circle*/
	    
	    if(a  > total || b > total || c > total)  // eliminating non possibilities  
	        cout << "-1\n";
	        
	    else{
	        if(c + abs(b-a) <= total)   // if c is in 1st half of circle
	            cout << c + abs(b-a) << endl;
	        
	        else if(c + abs(b-a) > total)   // if c is in 2nd half of circle
	            cout << c - abs(b-a) << endl;
	    }
	}
    return 0;
}
