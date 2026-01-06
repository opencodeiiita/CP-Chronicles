/*
Problem Statement:
  Solve Day-10 q002 from Binary Search. 
  Find the first index that satisfies a given condition in an array.

Approach:
  Used Binary Search to check mid elements efficiently until the answer is found.

Time Complexity: O(log n)
Space Complexity: O(n)

Example I/O:
  Input:
    5
    1 3 4 6 8
    4
  Output:
    2
*/

#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i <n;i++) cin >> arr[i];
    int target;
    cin >> target; 
    int left = 0 right = n - 1;
    int answer = -1;
    while(left <=right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] >= target) {
            answer =mid;
            right  mid - 1;
        } else {
            left =mid + 1;
        }
    }
    cout << answer << "\n"; 
    return 0;
}
