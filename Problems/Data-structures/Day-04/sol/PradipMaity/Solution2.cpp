#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;   // initial accumulator value
    int k;         // number of lists
    cin >> x >> k;

    // Read all lists
    vector<vector<long long>> lists(k);
    for(int i = 0; i < k; i++){
        int len;
        cin >> len;
        lists[i].resize(len);
        for(auto &v : lists[i]) cin >> v;
    }

    /*
     We can always only take the LEFTMOST element of a list.
     At any given time, every list exposes one "available" element:
       its current front.

     Among all available elements:
        - We want to choose the BEST possible number
        - Best means the largest value (since it increases x most)
     
     So we will maintain a MAX-HEAP of currently available elements.
     
     Each heap entry stores:
        value, list_index, position_in_that_list
    */
    priority_queue<array<long long, 3>> pq;

    // Initially push the first element of each list
    for(int i = 0; i < k; i++){
        pq.push({lists[i][0], i, 0});
    }

    /*
     Now we simulate the game.

     While there are available options:
       1️⃣ Take the largest available number
       2️⃣ Check if adding it keeps x >= 0
          - If YES → take it, update x
                  → push the next element of that list (if exists)
          - If NO  → we MUST discard it permanently
                     because:
                     if we can't afford this number now when it is
                     the BEST option, we will NEVER afford it later
                     (future choices are <= current max)
    */
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();

        long long val = top[0];  // value of element
        int li = top[1];         // which list
        int idx = top[2];        // index inside list

        // Check if we can safely add this number
        if(x + val >= 0){
            x += val;  // Take it

            // Move to the next element of this list
            if(idx + 1 < (int)lists[li].size()){
                pq.push({lists[li][idx + 1], li, idx + 1});
            }
        }
        else{
            // We can't take it now, and will never be able to in future.
            // So just ignore it and do NOT push further elements from this list.
        }
    }

    // Final best possible accumulator value
    cout << x << '\n';
}

// Submission Link : https://codeforces.com/problemset/status?my=on