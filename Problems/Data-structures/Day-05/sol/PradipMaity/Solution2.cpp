#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<array<long long,3>> customers(n);
    /*
        store: {arrival, departure, original_index}
        because we must later print room numbers
        in the same order as the input
    */
    for(int i = 0; i < n; i++){
        cin >> customers[i][0] >> customers[i][1];
        customers[i][2] = i;
    }

    // sort customers by arrival day
    sort(customers.begin(), customers.end());

    /*
        We use a MIN-HEAP storing:
            {departure_day, room_id}

        It keeps track of which room gets free the earliest.

        Logic:
        -------
        For each customer in order of arrival:
            - check the room with smallest departure day
            - if that room departs strictly BEFORE
              current arrival => we can reuse that room
            - otherwise => we must create a new room
    */
    priority_queue<
        array<long long,2>,
        vector<array<long long,2>>,
        greater<array<long long,2>>
    > pq;

    vector<int> ans(n);   // room assignment for each customer
    int rooms = 0;        // total rooms used

    for(auto &c : customers){
        long long start = c[0];
        long long end   = c[1];
        int idx         = c[2];

        if(!pq.empty() && pq.top()[0] < start){
            // reuse room whose customer finished earliest
            auto best = pq.top();
            pq.pop();

            int room_id = best[1];
            ans[idx] = room_id;

            // this room will now be busy until `end`
            pq.push({end, room_id});
        }
        else{
            // need new room
            rooms++;
            ans[idx] = rooms;

            pq.push({end, rooms});
        }
    }

    // print result
    cout << rooms << '\n';
    for(int x : ans) cout << x << ' ';
}


// Submission Link:- https://cses.fi/problemset/result/15787142/