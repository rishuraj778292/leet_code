/*
52. N-Queens II

Hard

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

 

Example 1:


Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 9
*/
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isSafe(vector<vector<int>>& board, int n, int row, int col) {
        int i = row;
        int j = col;
        while (j >= 0) {
            if (board[i][j] == 1) {
                return false;
            }
            j--;
        }
        j = col;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 1) {
                return false;
            }
            i--;
            j--;
        }
        i = row;
        j = col;
        while (i < n && j >= 0) {
            if (board[i][j] == 1) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(vector<vector<int>>& board, int n, int& count,  int  col) {
        if (col >= n) {
            count++;
            return;
        }

        for (int row = 0; row < n; row++) {
            if (board[row][col] == 0) {
                if (isSafe(board, n, row, col)) {
                    board[row][col] = 1;
                    solve(board, n, count, col + 1);
                    board[row][col] = 0;
                }
            }
        }
        return;
    }
    int totalNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
       
        int count = 0;
        solve(board, n, count, 0);
        return count;
    }
};


int main(){

 return 0;
}
