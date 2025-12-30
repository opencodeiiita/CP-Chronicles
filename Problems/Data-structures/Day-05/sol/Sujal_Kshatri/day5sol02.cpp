//submission link - https://cses.fi/problemset/result/15782979/

/*
Approach:
Sort customers by arrival day while keeping original indices.
Use a priority queue to track rooms by earliest departure.
If the earliest departing room is free before current arrival,
reuse that room; otherwise allocate a new room.
Store assigned room numbers and print them in original order.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<array<long long, 3>> customers(n);
    for (int i = 0; i < n; i++) {
        cin >> customers[i][0] >> customers[i][1];
        customers[i][2] = i;
    }

    sort(customers.begin(), customers.end());

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    vector<int> room(n);
    int rooms = 0;

    for (auto &c : customers) {
        long long start = c[0], end = c[1];
        int idx = c[2];

        if (!pq.empty() && pq.top().first < start) {
            auto top = pq.top();
            pq.pop();
            room[idx] = top.second;
            pq.push({end, top.second});
        } else {
            rooms++;
            room[idx] = rooms;
            pq.push({end, rooms});
        }
    }

    cout << rooms << "\n";
    for (int i = 0; i < n; i++) {
        cout << room[i] << " ";
    }

    return 0;
}

/*
Time Complexity: O(n log n)
Space Complexity: O(n)
*/
