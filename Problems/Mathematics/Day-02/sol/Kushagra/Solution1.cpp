/*PROBLEM STATEMENT :
Hossam woke up bored, so he decided to create an interesting array with his friend Hazem.
 
You are given an array of n positive integers
a1, a2, ..., an.
 
Hossam will choose a number ai and Hazem will choose a number aj.
 
Your task is to count the number of index pairs (i, j) such that:
 
1 ≤ i, j ≤ n
i ≠ j
The absolute difference |ai − aj| is equal to the maximum absolute difference over all pairs in the array
Approach : we sort the array and count the freq of min and max integers since all elements are positive
the answer will simply be max freq* min freq * 2
Space Complexity : O(n) because we make an array of size n
Input
2
5
6 2 3 8 1
6
7 2 8 3 2 10
Output
2
4
submission : https://codeforces.com/problemset/submission/1771/355287340
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >>t;
    while(t--)
    {      
        int n;
        cin >>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin >>arr[i];
        sort(arr,arr+n);
        long long int min=arr[0],max=arr[n-1],minC=0,maxC=0;
        for(int i=0;i<n;i++)
        if(arr[i]==min)minC++;
        for(int i=n-1;i>=0;i--)
        if(arr[i]==max)maxC++;
        if(max!=min)
        cout <<minC*maxC*2<<"\n";
        else
        cout <<1LL*n*(n-1)<<"\n";
    }
}
