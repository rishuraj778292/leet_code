/*

1351. Count Negative Numbers in a Sorted Matrix

Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

 

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100
 

Follow up: Could you find an O(n + m) solution?

*/

class Solution {
public:
    // void binarySearch(vector<int>& arr, int& count) {
    //     int s = 0;
    //     int e = arr.size() - 1;
    //     int index = arr.size();
    //     while (s <= e) {
    //         int mid = (s + e) / 2;
    //         if (arr[mid] < 0) {
    //             index = mid;
    //             e = mid - 1;
    //         } else {
    //             s = mid + 1;
    //         }
    //     }
    //     count += arr.size()-index;
    // }
    int countNegatives(vector<vector<int>>& grid) {
        // brute force-> O(m*n)

        // int count = 0;
        // for (int i = 0; i < grid.size(); i++) {
        //     for (int j = 0; j < grid[0].size(); j++) {
        //         if (grid[i][j] < 0) {
        //             count++;
        //         }
        //     }
        // }
        // return count;

        // by binary search->O(m*logn)
        // int count = 0;
        // for (int i = 0; i < grid.size(); i++) {
        //     binarySearch(grid[i], count);
        // }
        // return count;

        // optimized -> O(m+n)
        int countNegative = 0;
        int noOfCol = grid[0].size();
        int row = grid.size()-1;
        int column =0;
        while(row>=0 && column<noOfCol){
            if(grid[row][column]<0){
                countNegative += noOfCol-column;
                row--;
            }
            else{
                column++;
            }
        }
        return countNegative;
    }
};