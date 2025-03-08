/*
1524. Number of Sub-arrays With Odd Sum
Solved
Medium
Topics
Companies
Hint
Given an array of integers arr, return the number of subarrays with an odd sum.

Since the answer can be very large, return it modulo 109 + 7.

 

Example 1:

Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.
Example 2:

Input: arr = [2,4,6]
Output: 0
Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.
Example 3:

Input: arr = [1,2,3,4,5,6,7]
Output: 16
 

Constraints:

1 <= arr.length <= 105
1 <= arr[i] <= 100
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            // approach -1
            // int numofsubarrays = 0;
            // for (int i = 0; i < arr.size(); i++) {
            //     int sum = 0;
            //     for (int j = i; j < arr.size(); j++) {
            //         sum += arr[j];
            //         if (sum & 1) {
            //             numofsubarrays++;
            //         }
            //     }
            // }
            // return numofsubarrays;
    
            // approach-2 prefix sum
            int M = 1e9+7;
            int prefSum = 0;
            int oddCount = 0;
            int evenCount = 1;
            int count = 0;
            for(int i=0;i<arr.size();i++){
                prefSum +=  arr[i];
                if(prefSum & 1){ // odd + even = odd
                    count += evenCount;
                    oddCount++;
                }
                else{ // even + odd = odd
                    count += oddCount%M;
                    evenCount++;
                }
                count = count % M;
            }
            return count;
        }
    };

int main(){

 return 0;
}