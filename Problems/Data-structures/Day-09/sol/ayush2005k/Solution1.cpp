/*
Problem: Salary Queries
Source: CSES
Problem Link: https://cses.fi/problemset/task/1144/

Short Problem Statement:
A company has n employees with salaries.
You need to process two types of queries:
1) Update an employee’s salary.
2) Count how many employees have salaries in a given range [a, b].

Approach:
- Use coordinate compression because salaries can be up to 1e9.
- Maintain frequencies of salaries using a Fenwick Tree (Binary Indexed Tree).
- For update queries, decrease the old salary count and increase the new one.
- For range queries, use prefix sums from the Fenwick Tree.

Time Complexity:
O((n + q) log (n + q))

Space Complexity:
O(n + q)

Example:
Input:
5 3
3 7 2 2 5
? 2 3
! 3 6
? 2 3

Output:
3
2

Submission Link:
https://cses.fi/paste/129b78ff774776c0f188fe/
*/

#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void update(int i, int v) {
        for (; i <= n; i += i & -i)
            bit[i] += v;
    }

    int query(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> salary(n);
    for (int i = 0; i < n; i++)
        cin >> salary[i];

    vector<int> all = salary;
    vector<pair<char, pair<int, int>>> queries;

    for (int i = 0; i < q; i++) {
        char type;
        cin >> type;
        if (type == '!') {
            int k, x;
            cin >> k >> x;
            queries.push_back({type, {k - 1, x}});
            all.push_back(x);
        } else {
            int a, b;
            cin >> a >> b;
            queries.push_back({type, {a, b}});
            all.push_back(a);
            all.push_back(b);
        }
    }

    // Coordinate compression
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    auto get_id = [&](int x) {
        return int(lower_bound(all.begin(), all.end(), x) - all.begin()) + 1;
    };

    Fenwick fw(all.size());

    for (int x : salary)
        fw.update(get_id(x), 1);

    for (auto &qr : queries) {
        if (qr.first == '!') {
            int idx = qr.second.first;
            int x = qr.second.second;

            fw.update(get_id(salary[idx]), -1);
            fw.update(get_id(x), 1);
            salary[idx] = x;
        } else {
            int a = qr.second.first;
            int b = qr.second.second;
            cout << fw.query(get_id(b)) - fw.query(get_id(a) - 1) << "\n";
        }
    }

    return 0;
}
