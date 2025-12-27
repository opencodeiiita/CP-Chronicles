/*
We need to evaluate:

Sum over i = 1..N
 Sum over j = 1..N
  Sum over k = 1..i
   Sum over l = 1..j
     gcd(k, i) * gcd(l, j) * gcd(i, j)

----------------------------------------------
STEP 1 — Reduce Inner Summations
----------------------------------------------
Define a known function:

G(n) = sum(gcd(x, n)) for x from 1 to n

There is a known number theory identity:
G(n) = sum over all divisors d of n ( d * phi(n / d) )

Where phi() is Euler Totient function.

So expression reduces to:

Answer = Σ Σ  G(i) * G(j) * gcd(i, j)

----------------------------------------------
STEP 2 — Group by gcd(i, j)
----------------------------------------------
Let g = gcd(i, j)

Write:
i = g * a
j = g * b
and gcd(a, b) = 1

So:
Answer = Σ g * Σ ( G(g*a) * G(g*b) ) for all gcd(a,b)=1

----------------------------------------------
STEP 3 — Enforce gcd(a, b) = 1
----------------------------------------------
Use Mobius Inversion Trick:

[gcd(a,b)=1] = Σ μ(t)   for all t dividing gcd(a,b)

Final transformation becomes:

Answer =
Σ(g = 1 to N)
 g *
 Σ(t = 1 to N/g)
  μ(t) *
  ( Σ G(g * t * x) )^2

----------------------------------------------
STEP 4 — Implementation Plan
----------------------------------------------
1️.Precompute phi[] using linear sieve
2️.Precompute Möbius μ[] using same sieve
3️.Compute G(n) using divisor contribution
4️.Build prefix sums of G
5️.Apply final summation efficiently

Time Complexity ≈ O(N log N)
Works for N ≤ 1e6
*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 1000000;

long long phi[MAXN+1], mu[MAXN+1], G[MAXN+1];
bool prime[MAXN+1];
vector<int> primes;

// Modular helper to avoid overflow
long long addmod(long long a, long long b){
    a += b;
    if(a >= MOD) return a - MOD;
    return a;
}

long long mulmod(long long a, long long b){
    return (a % MOD) * (b % MOD) % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    /* ------------------------------------------------
       STEP A — Compute Euler Totient and Mobius Function
       Using Linear Sieve
    ------------------------------------------------ */
    phi[1] = mu[1] = 1;

    for(int i = 2; i <= N; i++){
        if(!prime[i]){
            primes.push_back(i);
            phi[i] = i - 1;   // phi(p) = p-1 when p is prime
            mu[i] = -1;       // μ(p) = -1
        }

        for(int p : primes){
            if(1LL * p * i > N) break;
            prime[p*i] = true;

            if(i % p == 0){
                // p divides i ⇒ special case
                phi[p*i] = phi[i] * p;
                mu[p*i] = 0;   // μ becomes zero if squared prime divides
                break;
            } 
            else {
                // otherwise multiplicative property
                phi[p*i] = phi[i] * (p - 1);
                mu[p*i] = -mu[i];
            }
        }
    }

    /* ------------------------------------------------
       STEP B — Compute G(n)
       G(n) = Σ (d divides n) d * phi(n/d)
       We do divisor contribution style
    ------------------------------------------------ */
    for(int d = 1; d <= N; d++){
        for(int m = d; m <= N; m += d){
            G[m] += 1LL * d * phi[m/d];
            if(G[m] >= 1LL * MOD * MOD) 
                G[m] %= MOD;   // avoid overflow
        }
    }

    for(int i = 1; i <= N; i++)
        G[i] %= MOD;

    /* ------------------------------------------------
       STEP C — Prefix sums of G
       Needed for block summation in final formula
    ------------------------------------------------ */
    vector<long long> pref(N+1);
    for(int i = 1; i <= N; i++)
        pref[i] = addmod(pref[i-1], G[i]);

    long long ans = 0;

    /* ------------------------------------------------
       STEP D — Apply Final Derived Formula
       Double loop on g and t
       Uses Möbius μ to enforce gcd=1 condition
    ------------------------------------------------ */
    for(int g = 1; g <= N; g++){
        for(int t = 1; t * g <= N; t++){
            if(mu[t] == 0) continue;

            int M = N / (g * t);

            // sum of G values in block multiples
            long long S = pref[g*M] - pref[g*(t-1)];
            S = (S % MOD + MOD) % MOD;

            // contribution term:
            long long contrib =
                mulmod(
                    mulmod(g, mu[t]),
                    mulmod(S, S)
                );

            ans = (ans + contrib) % MOD;
        }
    }

    cout << (ans + MOD) % MOD;
}
