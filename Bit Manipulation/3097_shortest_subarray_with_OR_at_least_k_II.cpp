/*

3097. Shortest Subarray With OR at Least K II

Medium

You are given an array nums of non-negative integers and an integer k.

An array is called special if the bitwise OR of all of its elements is at least k.

Return the length of the shortest special non-empty 
subarray
 of nums, or return -1 if no special subarray exists.

 

Example 1:

Input: nums = [1,2,3], k = 2

Output: 1

Explanation:

The subarray [3] has OR value of 3. Hence, we return 1.

Example 2:

Input: nums = [2,1,8], k = 10

Output: 3

Explanation:

The subarray [2,1,8] has OR value of 11. Hence, we return 3.

Example 3:

Input: nums = [1,2], k = 0

Output: 1

Explanation:

The subarray [1] has OR value of 1. Hence, we return 1.

 

Constraints:

1 <= nums.length <= 2 * 105
0 <= nums[i] <= 109
0 <= k <= 109
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // int getLengthBybrute(vector<int>& nums, int k) {
    //     int length = INT_MAX;
    //     for (int i = 0; i < nums.size(); i++) {
    //         for (int j = i; j < nums.size(); j++) {
    //             int check = nums[i];
    //             for (int k = i + 1; k <= j; k++) {
    //                 check = check | nums[k];
    //             }
    //             if (check >= k) {
    //                 int newLength = (j - i) + 1;
    //                 length = min(newLength, length);
    //                 break;
    //             }
    //         }
    //     }
    //     if (length == INT_MAX) {
    //         return -1;
    //     } else {
    //         return length;
    //     }
    // }

    void updateBits(vector<int>& setBit, int num, int set) {
        for (int i = 0; i < setBit.size(); i++) {
            if (((num >> i) & 1) == 1) {
                setBit[i] += set;
            }
        }
    }
    int getValue(vector<int>& setBit) {
        int ans = 0;
        for (int i = 0; i < setBit.size(); i++) {
           if(setBit[i]>0){
            ans = ans | (1<<i);
           }
        }
        return ans;
    }
    int getMinLengthByslidingWindow(vector<int>& nums, int k) {
        int s = 0;
        int e = 0;
        int length = INT_MAX;
        vector<int> setBit(32, 0);
        while (e < nums.size()) {
            updateBits(setBit, nums[e], 1);
            while (s <= e && getValue(setBit) >= k) {
                int newLength = e - s + 1;
                length = min(length, newLength);
                updateBits(setBit, nums[s], -1);
                s++;
            }
            e++;
        }

        if (length != INT_MAX) {
            return length;
        } else {
            return -1;
        }
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        // return getLengthBybrute(nums, k);
        return getMinLengthByslidingWindow(nums, k);
    }
};
int main(){

 return 0;
}