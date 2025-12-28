

// Submission Link: - 
// https://codeforces.com/contest/343/submission/355549255
// Explanation of Logic:

// Time Complexity - O(log(min(a,b)))
// Space Complexity - O(1)

// 1. The If Condition (Perfect Division):
//    - checks if 'a' is perfectly divisible by 'b' (remainder is 0).
//    - If true, this represents a whole number resistance. It means the 
//      target can be built purely with series resistors, with no parallel 
//      branches needed.
//    - We simply output 'a / b' as the total count.

// 2. The Else Block (Euclidean Division Lemma):
//    - If there is a remainder, we enter the loop to handle the fractional part
//      (representing the parallel branches).
//    - 'count' starts with the integer part of the first division.
//    - Inside the while loop:
//      'd / c' finds the integer part of the inverted remainder.
//       We add this to 'count'.
//       We swap variables to perform the mathematical inversion (1/x) 
//       for the next iteration.

      

#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b;
    cin>>a>>b;
    if(a%b == 0){
        cout<<a/b;
    }
    else {
        long long c = a%b;
        long long d = b;
        long long count = a/b;
        while(c != 0){
            count += d/c;
            long long temp = d%c;
            d = c;
            c = temp;
        }
        cout<<count;
    }
    return 0;
}
