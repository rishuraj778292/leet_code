/*
2593. Find Score of an Array After Marking All Elements
Solved
Medium

You are given an array nums consisting of positive integers.

Starting with score = 0, apply the following algorithm:

Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
Add the value of the chosen integer to score.
Mark the chosen element and its two adjacent elements if they exist.
Repeat until all the array elements are marked.
Return the score you get after applying the above algorithm.

 

Example 1:

Input: nums = [2,1,3,4,5,2]
Output: 7
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,1,3,4,5,2].
- 2 is the smallest unmarked element, so we mark it and its left adjacent element: [2,1,3,4,5,2].
- 4 is the only remaining unmarked element, so we mark it: [2,1,3,4,5,2].
Our score is 1 + 2 + 4 = 7.
Example 2:

Input: nums = [2,3,5,1,3,2]
Output: 5
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,3,5,1,3,2].
- 2 is the smallest unmarked element, since there are two of them, we choose the left-most one, so we mark the one at index 0 and its right adjacent element: [2,3,5,1,3,2].
- 2 is the only remaining unmarked element, so we mark it: [2,3,5,1,3,2].
Our score is 1 + 2 + 2 = 5.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
// private:
//     int minElementIndex(vector<int>& nums, unordered_map<int, bool> vis) {
//         int index = -1;
//         int min = INT_MAX;
//         for (int i = 0; i < nums.size(); i++) {
//             if (!vis[i] && nums[i] < min) {
//                 min = nums[i];
//                 index = i;
//             }
//         }
//         return index;
//     }

public:
    long long findScore(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        // approach - 1 (brute force by myself)-(O(n^2))
        //  unordered_map<int,bool>vis;
        //  long long int score = 0;
        //  int smallestIntegerIndex=minElementIndex(nums,vis);
        //  while(smallestIntegerIndex!=-1){
        //      vis[smallestIntegerIndex]=true;
        //      score+=nums[smallestIntegerIndex];
        //      if(smallestIntegerIndex-1>=0){
        //          vis[smallestIntegerIndex-1]=true;
        //      }
        //      if(smallestIntegerIndex+1<nums.size()){
        //          vis[smallestIntegerIndex+1]=true;
        //      }
        //      smallestIntegerIndex=minElementIndex(nums,vis);
        //  }
        //  return score;

        // approach -2 (using min heap  by myself )- t.c -> O(n log n)
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }
        unordered_map<int, bool> vis;
        long long int score = 0;
        //  while(!pq.empty()){
        //     auto temp=pq.top();
        //     cout<<temp.first<<" "<<temp.second<<endl;
        //     pq.pop();
        //  }
        while (!pq.empty()) {
            pair<int, int> temp = pq.top();
            if (vis[temp.second]) {
                pq.pop();
            } else {
                pq.pop();
                score += temp.first;
                vis[temp.second] = true;
                vis[temp.second - 1] = true;
                vis[temp.second + 1] = true;
            }
        }
        return score;
    }
};
int main(){

 return 0;
}