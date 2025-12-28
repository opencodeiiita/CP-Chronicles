Submission Link: https://codeforces.com/contest/1225/submission/355608300

/*
So first I made a vector t which stores data of type pair(int, int) and a map c from vector storing pair(int, int) to int. Now I take input from user each element
of array a given as input. Now, I do prime factorisation of the input number and if the power is not a multiple of k then I store it in vector t as 
pair(prime no., power%k). After the loop runs up to the square root of a, if a is still not 1, then the remaining value is a prime number, so we store the pair (a, 1). 
Then, I increment the value in the map c for the key t[i], which counts how many times this specific signature has appeared. Now in next for loop I made a vector s 
which also store pair(int, int). Now, I iterated through all the pair in each vector of t and added a pair(p.first, k - p.second) to vector s. This creates the 
"complement" signature—basically what prime factors and powers are missing to make a perfect k-th power. Then, I look up this vector s in the map c and add its 
frequency to ans. I also check if s is equal to t[i] (meaning the number is its own complement); if so, I decrement ans by 1 to avoid counting the number pairing 
with itself. Finally, I divide ans by 2 to remove double counting (since pair (A, B) and (B, A) are the same) and print the result.

Time Complexity: O(N * sqrt(V)), where N is the number of elements and V is the maximum value of an element (since we iterate up to sqrt(V) for factorization).
Space Complexity: O(N), as we store the prime signatures for all N elements in the vector and map.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector <pair <int, int> > t[n];
    map<vector<pair<int, int>>, int> c;
  
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        for (int j = 2; j * j <= a; j++) {
            if (a % j == 0) {
                int p = 0;
                while (a % j == 0) {
                    a /= j;
                    p++;
                }
                if (p % k > 0) {
                    t[i].push_back({j, p % k});
                }
            }
        }
        if (a != 1) {
            t[i].push_back({a, 1});
        }
        c[t[i]]++;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> s;
        for (pair<int, int> p : t[i]) {
            s.push_back({p.first, k - p.second});
        }
        ans += c[s];
        if (s == t[i]) {
            ans--;
        }
    }
    ans /= 2;
    cout << ans << endl;
}
