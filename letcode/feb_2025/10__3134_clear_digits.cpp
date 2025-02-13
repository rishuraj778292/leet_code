/*
3174. Clear Digits
Solved
Easy
Topics
Companies
Hint
You are given a string s.

Your task is to remove all digits by doing this operation repeatedly:

Delete the first digit and the closest non-digit character to its left.
Return the resulting string after removing all digits.

 

Example 1:

Input: s = "abc"

Output: "abc"

Explanation:

There is no digit in the string.

Example 2:

Input: s = "cb34"

Output: ""

Explanation:

First, we apply the operation on s[2], and s becomes "c4".

Then we apply the operation on s[1], and s becomes "".

 

Constraints:

1 <= s.length <= 100
s consists only of lowercase English letters and digits.
The input is generated such that it is possible to delete all digits.
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string clearDigits(string s) {
            // approach - 1 O(n);
            string ans="";
            for(int i=0;i<s.size();i++){
                if(isdigit(s[i])){
                    if(!s.empty()){
                        ans.pop_back();
                    }
                }
                else{
                    ans.push_back(s[i]);
                }
            }
            return ans;
        }
    };
int main(){

 return 0;
}