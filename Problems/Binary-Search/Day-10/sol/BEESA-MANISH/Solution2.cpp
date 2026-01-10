/*
Submission link : https://www.codechef.com/viewsolution/1223692024

TC -O(N)
SC-O(N)


Approach:
Use two pointers l and r to form a sliding window.
Track whether the sequence can continue by choosing from array a or b using can_a and can_b.
For each l, try to extend r while the sequence remains strictly increasing.
Count all valid subarrays starting at l by adding (r - l + 1) to the answer.

*/


#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> can_a(n, 0), can_b(n, 0);
    long long total = 0;
    int r = -1;

    for (int l = 0; l < n; l++) {
        if (r < l) {
            r = l;
            can_a[r] = 1;
            can_b[r] = 1;
        } else {
            if (can_a[l] && can_b[l]) {
                // already maxed
            } else {
                can_a[l] = 1;
                can_b[l] = 1;
                for (int i = l; i < r; i++) {
                    int next_a = (can_a[i] && a[i] < a[i + 1]) || (can_b[i] && b[i] < a[i + 1]);
                    int next_b = (can_a[i] && a[i] < b[i + 1]) || (can_b[i] && b[i] < b[i + 1]);
                    if (next_a == can_a[i + 1] && next_b == can_b[i + 1]) break;
                    can_a[i + 1] = next_a;
                    can_b[i + 1] = next_b;
                }
            }
        }

        while (r + 1 < n) {
            int next_a = (can_a[r] && a[r] < a[r + 1]) || (can_b[r] && b[r] < a[r + 1]);
            int next_b = (can_a[r] && a[r] < b[r + 1]) || (can_b[r] && b[r] < b[r + 1]);
            if (next_a || next_b) {
                r++;
                can_a[r] = next_a;
                can_b[r] = next_b;
            } else {
                break;
            }
        }
        total += (r - l + 1);
    }
    cout << total << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}