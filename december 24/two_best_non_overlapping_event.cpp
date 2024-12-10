/*
2054. Two Best Non-Overlapping Events

You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.

Return this maximum sum.

Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.

 

Example 1:


Input: events = [[1,3,2],[4,5,2],[2,4,3]]
Output: 4
Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.
Example 2:

Example 1 Diagram
Input: events = [[1,3,2],[4,5,2],[1,5,5]]
Output: 5
Explanation: Choose event 2 for a sum of 5.
Example 3:


Input: events = [[1,5,3],[1,5,1],[6,6,5]]
Output: 8
Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.
 

Constraints:

2 <= events.length <= 105
events[i].length == 3
1 <= startTimei <= endTimei <= 109
1 <= valuei <= 106
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findIndex(vector<vector<int>>& events,int target){
        int left=0,right=events.size()-1,ans=-1;
        while(left<=right){
            int mid=(left+right)>>1;
            if(events[mid][0]>=target){
                ans = mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;

    }
    int maxTwoEvents_helper(vector<vector<int>>& events, int index, int count,vector<vector<int>>&dp) {
        if (index >= events.size()) {
            return 0;
        }
        if(count>=2){
            return 0;
        }
        if(dp[index][count]!=-1){
            return dp[index][count];
        }
        int nextIndex = findIndex(events,events[index][1]+1);
        int take=events[index][2]+maxTwoEvents_helper(events,nextIndex,count+1,dp);
        int skip = maxTwoEvents_helper(events,index+1,count,dp);
        
        return dp[index][count]=max(take,skip);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        vector<vector<int>>dp((events.size()+1),vector<int>(3,-1));
        return maxTwoEvents_helper(events, 0, 0,dp);
    }
};
int main(){

 return 0;
}