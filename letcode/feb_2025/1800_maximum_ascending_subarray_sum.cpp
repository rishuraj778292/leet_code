/*

Testcase
Testcase
Test Result
Code
1800. Maximum Ascending Subarray Sum
Solved
Easy
Topics
Companies
Hint
Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.

A subarray is defined as a contiguous sequence of numbers in an array.

A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi  < numsi+1. Note that a subarray of size 1 is ascending.

 

Example 1:

Input: nums = [10,20,30,5,10,50]
Output: 65
Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.
Example 2:

Input: nums = [10,20,30,40,50]
Output: 150
Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum of 150.
Example 3:

Input: nums = [12,17,15,13,10,11,12]
Output: 33
Explanation: [10,11,12] is the ascending subarray with the maximum sum of 33.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100


editorial:-
Overview
We need to find the highest possible sum of an ascending subarray in a given array of positive integers. An ascending subarray is a contiguous sequence where each element is strictly smaller than the next (i.e., nums[i] < nums[i+1] for all valid indices). A subarray of size 1 is always considered ascending because there are no adjacent elements to compare.

Note: There is a difference between "ascending" and "non-decreasing." "Ascending" means strictly increasing, where each value is greater than the previous one. On the other hand, "non-decreasing" allows the values to stay the same or increase, so equality is permitted.
For example:

1 2 3 4 5 is ascending (strictly increasing).
1 2 2 3 3 4 5 is non-decreasing (values can remain the same or increase).
Approach 1: Brute-Force
Intuition
A simple logical approach to solving this problem is to check all possible ascending subarrays to find the largest sum. We can start by treating each element as the beginning of a new subarray and calculate its sum. If the element next to it is greater, we can extend the current subarray by adding it to the sum. If the next element is not greater, we stop extending and consider the next element as the start of a new subarray. We repeat this process for each element, keeping track of the largest sum found.

While this is straightforward, it requires checking every possible subarray using nested loops. This can become inefficient because the number of subarrays increases with the size of the input, resulting in a time complexity of O(n 
2
 ). Although this method works fine with small inputs due to relatively easy constraints, it is not ideal for larger arrays because it involves checking many possible subarrays.

Algorithm
Initialize maxSum to 0, which will store the maximum sum of an ascending subarray.

Use an outer loop to iterate over each element in the array (nums[startIdx]):

Set currentSubarraySum to nums[startIdx] to start a new ascending subarray from this element.
Use an inner loop to check the next elements forming an ascending subarray:

Continue adding to currentSubarraySum while the next element (nums[endIdx]) is greater than the previous element (nums[endIdx - 1]).
Stop the inner loop when the subarray is no longer ascending or when the end of the array is reached.
After checking the subarray, update maxSum if currentSubarraySum is greater than the current maxSum.

After processing all possible subarrays, return maxSum, which contains the largest sum of an ascending subarray.

Implementation

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0;

        // Outer loop to start from each element in the array
        for (int startIdx = 0; startIdx < nums.size(); startIdx++) {
            int currentSubarraySum = nums[startIdx];

            // Inner loop to check the next elements forming an ascending
            // subarray
            for (int endIdx = startIdx + 1;
                 endIdx < nums.size() && nums[endIdx] > nums[endIdx - 1];
                 endIdx++) {
                currentSubarraySum += nums[endIdx];
            }

            // Update maxSum if we find a larger ascending subarray sum
            maxSum = max(maxSum, currentSubarraySum);
        }

        return maxSum;
    }
};

Complexity Analysis
Let n be the size of the input array nums.

Time complexity: O(n 
2
 )

The algorithm uses a nested loop structure. The outer loop runs n times, iterating over each element in the array. For each iteration of the outer loop, the inner loop starts from the current element and continues as long as the next element is greater than the previous one (forming an ascending subarray). In the worst case, the inner loop could run up to n times (e.g., when the entire array is strictly increasing).

Therefore, the time complexity is O(n 
2
 ).

Space complexity: O(1)

The algorithm uses a constant amount of extra space. The variables maxSum, currentSubarraySum, startIdx, and endIdx are the only additional space used, and they do not depend on the size of the input array. No additional data structures or recursive calls are used that would increase the space complexity.

Therefore, the space complexity is O(1).

Approach 2: Linear Scan
Intuition
Instead of using the brute-force method of checking every possible subarray, which is inefficient, we can solve the problem in a single pass through the array.

The key idea is to keep extending the current subarray as long as it stays ascending. If we encounter an element that isn’t greater than the previous one, we stop and compare the current subarray’s sum with the largest sum we’ve found so far and update it if the current element is not greater than the previous one. Then, we reset the current sum to the current element and start a new subarray from there.

This strategy works because, with all numbers being positive, extending a subarray will always increase its sum. Thus, we should never start a new subarray when we can extend the current one. For an added challenge, try solving the similar problem 53. Maximum Subarray, where the numbers are not restricted to be positive.

By following this idea, we only need to go through the array once. At the end of the loop, we perform a final check to ensure we account for the last subarray, just in case it had the largest sum.

The algorithm is visualized below:

Current

Algorithm
Initialize maxSum to 0, which will store the maximum sum of an ascending subarray.

Initialize currentSubarraySum to the first element of the nums array, which tracks the sum of the current ascending subarray.

Loop through the array starting from the second element:

Compare each element with the previous one:
If the current element is less than or equal to the previous one:
Update maxSum with the maximum value between the current maxSum and currentSubarraySum.
Reset currentSubarraySum to 0, as a new ascending subarray will start.
Add the current element's value to currentSubarraySum to continue summing the ascending subarray.
After the loop ends, perform a final check to account for the last ascending subarray:

Return the maximum value between maxSum and currentSubarraySum, which is the sum of the largest ascending subarray.
Implementation

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0;
        int currentSubarraySum = nums[0];

        // Loop through the array starting from the second element
        for (int currentIdx = 1; currentIdx < nums.size(); ++currentIdx) {
            if (nums[currentIdx] <= nums[currentIdx - 1]) {
                // If the current element is not greater than the previous one,
                // update maxSum
                maxSum = max(maxSum, currentSubarraySum);
                // Reset the sum for the next ascending subarray
                currentSubarraySum = 0;
            }
            currentSubarraySum += nums[currentIdx];
        }

        // Final check after the loop ends to account for the last ascending
        // subarray
        return max(maxSum, currentSubarraySum);
    }
};


Complexity Analysis
Let n be the size of the input array nums.

Time complexity: O(n)

The algorithm iterates through the array nums exactly once. During each iteration, it performs a constant amount of work: comparing the current element with the previous one, updating maxSum, and resetting currentSubarraySum if necessary. The max function, which is a built-in function, also operates in constant time O(1).

Therefore, the overall time complexity is linear with respect to the size of the input array.

Space complexity: O(1)

The algorithm uses a constant amount of extra space regardless of the input size. The variables maxSum and currentSubarraySum are the only additional space used, and they do not depend on the size of the input array.

Therefore, the space complexity is constant, O(1).


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = INT_MIN;
        int tempSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                tempSum += nums[i];
            } else {
                maxSum = max(maxSum, tempSum);
                tempSum = nums[i];
            }
        }
        maxSum = max(maxSum, tempSum);
        return maxSum;
    }
};

int main(){

 return 0;
}