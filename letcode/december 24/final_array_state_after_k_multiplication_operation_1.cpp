/*
3264. Final Array State After K Multiplication Operations I
Solved
Easy
Topics
Companies
Hint
You are given an integer array nums, an integer k, and an integer multiplier.

You need to perform k operations on nums. In each operation:

Find the minimum value x in nums. If there are multiple occurrences of the minimum value, select the one that appears first.
Replace the selected minimum value x with x * multiplier.
Return an integer array denoting the final state of nums after performing all k operations.

 

Example 1:

Input: nums = [2,1,3,5,6], k = 5, multiplier = 2

Output: [8,4,6,5,6]

Explanation:

Operation	Result
After operation 1	[2, 2, 3, 5, 6]
After operation 2	[4, 2, 3, 5, 6]
After operation 3	[4, 4, 3, 5, 6]
After operation 4	[4, 4, 6, 5, 6]
After operation 5	[8, 4, 6, 5, 6]
Example 2:

Input: nums = [1,2], k = 3, multiplier = 4

Output: [16,8]

Explanation:

Operation	Result
After operation 1	[4, 2]
After operation 2	[4, 8]
After operation 3	[16, 8]
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
1 <= k <= 10
1 <= multiplier <= 5
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
    int smallestElementIndex(vector<int>& nums) {
        int min = INT_MAX;
        int index = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < min) {
                min = nums[i];
                index = i;
            }
        }
        return index;
    }

    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            } else {
                return a.first > b.first;
            }
        }
    };

public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        // vector<int> ans = nums;
        // while (k) {
        //     k--;
        //     int index = smallestElementIndex(ans);
        //     ans[index] = ans[index] * multiplier;
        // }
        // return ans;

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }

        while (k) {
            k--;
            pair<int, int> smallest = pq.top();
            pq.pop();
            pq.push({smallest.first * multiplier, smallest.second});
        }
        vector<int> ans(pq.size());
        while (!pq.empty()) {
            auto temp = pq.top();
            ans[temp.second] = temp.first;
            pq.pop();
        }
        return ans;
    }
};
int main(){

 return 0;
}