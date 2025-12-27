/*PROBLEM STATEMENT :
There are n people standing in a circle. They are numbered from 1 to n in a clockwise order. The circle is even (i.e. n is even).

Each person is looking at the person standing exactly opposite him in the circle.

You are given three distinct integers a, b, and c. It is known that person a is looking at person b.

Determine the number of the person that person c is looking at.
If there are multiple answers, print any of them.
If there is no answer, print -1.

Approach : the length of the circle will be |a-b|*2 so if any of a,b,c is greater than this we print -1 if this is not true we print c+|a-b| if it exists in the circle otherwise we print c-|a-b| 
Time Complexity : O(1)
Space Complexity : O(1)
Input
7
6 2 4
2 3 1
2 4 10
5 3 4
1 3 2
2 5 4
4 3 2
Output
8
-1
-1
-1
4
1
-1
https://codeforces.com/problemset/submission/1560/355227237
*/
#include <iostream>
using namespace std;
int main() {
    int t;
    cin >>t;
    while(t--)
    {
        int a,b,c;
        cin >>a >>b>>c;
        int len=abs(a-b)*2;
        if(c>len||a>len||b>len)
        cout <<-1<<"\n";
        else
        {
            if(c+len/2<=len)
            cout <<c+len/2<<"\n";
            else
            cout << c-len/2<<"\n";
        }        
        
    }
}
