#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        long long cost = 0;
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i + 1);
            } 
            else if (s[i] == ')') {
                if (!st.empty()) {
                    cost += (i + 1 - st.top());
                    st.pop();
                } 
                else {
                    int forced_open = i;
                    cost += (i + 1 - forced_open);
                }
            }
        }

        cout << cost << '\n';
    }
    return 0;
}
