/*
2364. Count Number of Bad Pairs
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].

Return the total number of bad pairs in nums.

 

Example 1:

Input: nums = [4,1,3,3]
Output: 5
Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
There are a total of 5 bad pairs, so we return 5.
Example 2:

Input: nums = [1,2,3,4,5]
Output: 0
Explanation: There are no bad pairs.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109





EDITORIAL :-

Approach: Hash Map
Intuition
First, let's understand what makes a pair "good" rather than "bad". For any two positions i and j in our array, they form a good pair if the difference between their positions equals the difference between their values. Mathematically, we can write this as: j - i = nums[j] - nums[i].

Rearranging this equation gives us:

j−nums[j]=i−nums[i]
​
 
This transformation highlights a key insight: for two positions to form a good pair, the difference between their position and their value (position - value) must be the same. In other words, the value of j - nums[j] must match the value of i - nums[i]. This "position - value" difference is the key to identifying good pairs.

For example, if the array is nums = [1, 1, 2, 1] at positions 0, 1, 2, 3, then calculating position - number gives us [-1, 0, 0, 2]. Here, positions 1 and 2 both have the same tag 0, forming a good pair.

As the number of bad pairs would be the total number of pairs minus the number of good pairs, let's focus on finding the number of good pairs each element can make. Since an element can form a good pair only with elements occurring before it, we can iterate over the nums array and keep a running count of all the good pairs we find.

We can use a hash map to keep track of the counts of each position - number value as we iterate through the array. For each index j, the value j - nums[j] tells us how many indices before j could form good pairs with it. These counts are stored in the hash map.

For an index j, all previous indices 0 to j - 1 can potentially form pairs with it. This means j total pairs are possible.
Out of these, the number of good pairs is determined by the count of j - nums[j] stored in the hash map.
The difference between the total pairs (j) and the good pairs gives the number of bad pairs contributed by nums[j].
As we iterate, we keep updating the hash map with the current position - number values and accumulate the count of bad pairs. After processing the entire array, we return the total count of bad pairs.

The slideshow below demonstrates the algorithm in action:

Current

For a more comprehensive understanding of hash tables, check out the Hash Table Explore Card 🔗. This resource provides an in-depth look at hash tables, explaining their key concepts and applications with a variety of problems to solidify understanding of the pattern.

Algorithm
Initialize:
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long badPairs = 0;
        unordered_map<int, int> diffCount;

        for (int pos = 0; pos < nums.size(); pos++) {
            int diff = pos - nums[pos];

            // Count of previous positions with same difference
            int goodPairsCount = diffCount[diff];

            // Total possible pairs minus good pairs = bad pairs
            badPairs += pos - goodPairsCount;

            // Update count of positions with this difference
            diffCount[diff] = goodPairsCount + 1;
        }

        return badPairs;
    }
};

a variable badPairs to 0 to keep track of the total count of bad pairs.
a hash map diffCount to store the frequency of differences between position and value.
For each position pos from 0 to the length of the array:

Calculate the difference between the current position and its value (pos - nums[pos]).
Get the count of previous positions that had the same difference value, defaulting to 0 if not found.
Add to badPairs the number of total possible pairs up to the current position (pos) minus the count of good pairs (goodPairsCount).
Update the frequency map by incrementing the count for the current difference by 1.
Return the total count of bad pairs stored in badPairs.

Implementation

Complexity Analysis
Let n be the length of the input array nums.

Time complexity: O(n)

The algorithm iterates through the array exactly once. At each position, the operations performed (calculating difference, accessing, and updating the hash map) are all O(1) on average. Therefore, the total time complexity is linear with respect to the array length.

Space complexity: O(n)

The algorithm uses a hash map to store differences between position and value. In the worst case, each position could have a unique difference value, causing the hash map to store n key-value pairs. No other data structures that scale with input size are used. Therefore, the space complexity is O(n).


*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            // approach -1 -> O(n^2)
            // long long count=0;
            // for(int i=0;i<nums.size()-1;i++){
            //     for(int j=i+1;j<nums.size();j++){
            //          if(nums[j]-nums[i]!= j-i){
            //             count++;
            //          }                
            //     }
            // }
            // return count;
            // approach -2 
            unordered_map<int,int>freq;
           long long int badCount=0;
            for(int i=0;i<nums.size();i++){
                int diff = nums[i]-i;
                if(freq.find(diff)!=freq.end()){
                    badCount+=i-freq[diff];
                    freq[diff]++;
                }
                else{
                    badCount+= i;
                    freq[diff]++;
                    
                }
            }
            return badCount;
        }
    };

int main(){

 return 0;
}