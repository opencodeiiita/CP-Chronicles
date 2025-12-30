// submission link - https://cses.fi/problemset/result/15782926/

/*
Approach:
Traverse the array from left to right.
Use a stack to keep elements in increasing order.
For each element, remove all elements from the stack that are greater than or equal to it.
If the stack is empty, there is no smaller element on the left, so print 0.
Otherwise, the top of the stack gives the nearest smaller element’s index.
Push the current element with its index into the stack.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    stack<pair<long long, int>> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top().first >= arr[i]) {
            st.pop();
        }

        if (st.empty()) {
            cout << 0 << " ";
        } else {
            cout << st.top().second << " ";
        }

        st.push({arr[i], i + 1});
    }

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
