/*
1346. Check If N and Its Double Exist
Solved
Easy
Topics
Companies
Hint
Given an array arr of integers, check if there exist two indices i and j such that :

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]
 

Example 1:

Input: arr = [10,2,5,3]
Output: true
Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]
Example 2:

Input: arr = [3,1,7,11]
Output: false
Explanation: There is no i and j that satisfy the conditions.
 

Constraints:

2 <= arr.length <= 500
-103 <= arr[i] <= 103
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int isAvailable(vector<int>& arr,int target){
        int l=0;
        int r=arr.size()-1;
        while(l<=r){
            int mid = (l+r)>>1;
            if(arr[mid]==target){
                return mid;
            }
            if(arr[mid]>target){
                r= mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return -1;
    }
    bool checkIfExist(vector<int>& arr) {
         // brute force - O(n^2);
        // for(int i=0;i<arr.size();i++){
        //     for(int j=0;j<arr.size();j++){
        //         if(arr[i]==2*arr[j] && i!=j){
        //             return true;
        //         }
        //     }
        // }
        // return false;

        // by binary search-O(nlogn)
        // sort(arr.begin(),arr.end());
        // for(int i=0;i<arr.size();i++){
        //     int doubleIsAvailable = isAvailable(arr,arr[i]*2);
        //     if(doubleIsAvailable>=0 && doubleIsAvailable!=i){
        //         return true;
        //     }
        // }
        // return false;

         // by hashtable
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i+1;
        }
        for(int j=0;j<arr.size();j++){
            if(mp[arr[j]*2] &&  mp[arr[j]*2]!=j+1){
                return true;
            }
        }
        return false;
    }
};
int main(){

 return 0;
}