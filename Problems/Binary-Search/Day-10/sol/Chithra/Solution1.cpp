/*
Submission Link:
https://github.com/Chithra582/CP-Chronicles/pull/524

Problem Statement:
The problem statement for Day-10 q002.md was not provided in the repository.
Hence, a standard Binary Search problem is solved.

Chosen Problem:
Find First and Last Position of Element in Sorted Array

Problem Description:
Given a sorted array of integers nums and a target value,
find the starting and ending position of the target value.
If the target is not found, return [-1, -1].

Approach:
  1. First binary search to find the leftmost occurrence
  2. Second binary search to find the rightmost occurrence
  3. Modify the search boundaries based on matches

Time Complexity:
O(log n)

Space Complexity:
O(1)

Example:
Input:
nums = [5,7,7,8,8,10], target = 8

Output:
[3, 4]
*/

#include <bits/stdc++.h>
using namespace std;

int findFirst(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            ans = mid;
            high = mid - 1;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int findLast(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            ans = mid;
            low = mid + 1;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    int first = findFirst(nums, target);
    int last = findLast(nums, target);

    cout << first << " " << last << endl;
    return 0;
}
