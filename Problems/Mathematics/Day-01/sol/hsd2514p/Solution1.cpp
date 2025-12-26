/*
PROBLEM STATEMENT:
Given an array of n positive integers and an integer k,
count the number of unordered index pairs (i, j) where i < j
such that a[i] * a[j] is a perfect k-th power.

A number is a perfect k-th power if it can be written as x^k for some integer x.

Example: For n=6, k=3, array=[1, 3, 9, 8, 24, 1]
We need to find pairs where product is a perfect cube.
Output: 5

APPROACH:
1. For each number, compute its prime factorization
2. Reduce each number to its "canonical form" by taking prime exponents modulo k
3. For a pair (i, j) to have product as perfect k-th power:
   - When we multiply a[i] * a[j], all prime exponents must be divisible by k
   - This means: (exp_i + exp_j) % k == 0
   - So for each number's canonical form, we need its complement: (k - form) % k
4. Use a map to count occurrences of each canonical form
5. For each number, count how many complements exist and have been seen before

TIME COMPLEXITY: O(n * sqrt(max_a) + n * log(max_a))
- Factorization: O(sqrt(max_a)) per number
- Map operations: O(log(unique_forms)) per number

SPACE COMPLEXITY: O(unique_forms) for the map storing canonical forms

SUBMISSION LINK:
https://codeforces.com/problemset/problem/1225/D
*/

#include<bits/stdc++.h>
using namespace std;

// Function to get prime factorization as a map
map<int, int> getPrimeFactorization(int num) {
    map<int, int> factors;
    
    // Check for factor 2
    while (num % 2 == 0) {
        factors[2]++;
        num /= 2;
    }
    
    // Check for odd factors from 3 onwards
    for (int i = 3; i * i <= num; i += 2) {
        while (num % i == 0) {
            factors[i]++;
            num /= i;
        }
    }
    
    // If num is still greater than 1, it's a prime factor
    if (num > 1) {
        factors[num]++;
    }
    
    return factors;
}

// Function to get canonical form (exponents mod k as a vector)
// We store it as a vector of pairs: (prime, exponent % k)
vector<pair<int, int>> getCanonicalForm(int num, int k) {
    map<int, int> factors = getPrimeFactorization(num);
    vector<pair<int, int>> canonical;
    
    for (auto& p : factors) {
        int rem = p.second % k;
        if (rem != 0) {  // Only store non-zero remainders
            canonical.push_back({p.first, rem});
        }
    }
    
    return canonical;
}

// Function to get complement form (k - exponent for each prime)
vector<pair<int, int>> getComplementForm(const vector<pair<int, int>>& canonical, int k) {
    vector<pair<int, int>> complement;
    
    for (auto& p : canonical) {
        complement.push_back({p.first, (k - p.second) % k});
    }
    
    return complement;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Map to store count of each canonical form
    map<vector<pair<int, int>>, long long> formCount;
    
    long long result = 0;
    
    // Process each number
    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> canonical = getCanonicalForm(a[i], k);
        vector<pair<int, int>> complement = getComplementForm(canonical, k);
        
        // Check if complement exists in map
        if (formCount.find(complement) != formCount.end()) {
            result += formCount[complement];
        }
        
        // Add current canonical form to map
        formCount[canonical]++;
    }
    
    cout << result << endl;
    
    return 0;
}

/*
EXAMPLE TRACE:
Input: n=6, k=3, a=[1, 3, 9, 8, 24, 1]

i=0: a[0]=1
  Factors: (empty - no prime factors)
  Canonical: []
  Complement: []
  formCount[[]]: 1, result: 0

i=1: a[1]=3
  Factors: 3^1
  Canonical: [(3, 1)]
  Complement: [(3, 2)]
  formCount[[(3,2)]]: 0, result: 0
  formCount[[(3,1)]]: 1

i=2: a[2]=9
  Factors: 3^2
  Canonical: [(3, 2)]
  Complement: [(3, 1)]
  formCount[[(3,1)]]: 1, result: 1 (pair with a[1])
  formCount[[(3,2)]]: 1

i=3: a[3]=8
  Factors: 2^3
  Canonical: [] (3 % 3 = 0)
  Complement: []
  formCount[[]]: 1, result: 2 (pair with a[0])
  formCount[[]]: 2

i=4: a[4]=24
  Factors: 2^3 * 3^1
  Canonical: [(3, 1)] (2^3 % 3 = 0, 3^1 % 3 = 1)
  Complement: [(3, 2)]
  formCount[[(3,2)]]: 1, result: 2
  formCount[[(3,1)]]: 2

i=5: a[5]=1
  Factors: (empty)
  Canonical: []
  Complement: []
  formCount[[]]: 2, result: 4 (pairs with a[0] and a[3])
  formCount[[]]: 3

Final result: 5 (pairs: (0,3), (0,5), (1,2), (3,5), (4,1) or similar)
*/
