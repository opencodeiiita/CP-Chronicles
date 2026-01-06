/*
Problem Statement:
  Solve Day-10 q002 from Binary Search. 
  Find the first index that satisfies a given condition in an array.

Approach:
  Use Binary Search to check mid elements efficiently until the answer is found.

Time Complexity: O(log n)
Space Complexity: O(n)

Example I/O:
  Input:
    5
    1 3 4 6 8
  Output:
    2
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int left = 0, right = n - 1;
    int answer = -1;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        // Replace this with actual condition from q002.md
        if(arr[mid] % 2 == 0) { 
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << "\n";

    return 0;
}
