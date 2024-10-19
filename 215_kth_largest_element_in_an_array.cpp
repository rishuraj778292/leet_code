/*
215. Kth Largest Element in an Array

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // by max heap

        // // creating max heap

        // priority_queue<int>maxHeap;

        // // push all vector element in max Heap
        // for(int i =0 ; i<nums.size();i++){
        //     maxHeap.push(nums[i]);
        // }

        // //pop top element until k==1 , (top element of max heap is maximum)
        // while(k!=1){
        //     maxHeap.pop();
        //     k--;
        // }
        // // now top element is kth largest
        // return maxHeap.top();

        // by mean heap --> more optimize
        priority_queue<int,vector<int>,greater<int>>minHeap;

        for(int i =0;i<k;i++){
            minHeap.push(nums[i]);
        }

        for(int j =k;j<nums.size();j++){
            if(nums[j]>minHeap.top()){
                minHeap.pop();
                minHeap.push(nums[j]);
            }
        }

        return minHeap.top();
    }
};


int main(){
    return 0;
}

