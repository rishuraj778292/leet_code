/*
2981. Find Longest Special Substring That Occurs Thrice I
Solved
Medium
t
You are given a string s that consists of lowercase English letters.

A string is called special if it is made up of only a single character. For example, the string "abc" is not special, whereas the strings "ddd", "zz", and "f" are special.

Return the length of the longest special substring of s which occurs at least thrice, or -1 if no special substring occurs at least thrice.

A substring is a contiguous non-empty sequence of characters within a string.

 

Example 1:

Input: s = "aaaa"
Output: 2
Explanation: The longest special substring which occurs thrice is "aa": substrings "aaaa", "aaaa", and "aaaa".
It can be shown that the maximum length achievable is 2.
Example 2:

Input: s = "abcdef"
Output: -1
Explanation: There exists no special substring which occurs at least thrice. Hence return -1.
Example 3:

Input: s = "abcaba"
Output: 1
Explanation: The longest special substring which occurs thrice is "a": substrings "abcaba", "abcaba", and "abcaba".
It can be shown that the maximum length achievable is 1.
 

Constraints:

3 <= s.length <= 50
s consists of only lowercase English letters.
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumLength(string s) {
        // m-1 O(n^3)

        // unordered_map<string, int> substringCount;
        // for (int i = 0; i < s.size(); i++) {
        //     string subString = "";
        //     for (int j = i; j < s.size(); j++) {
        //         if (subString.empty() || subString.back() == s[j]) {
        //             subString += s[j];
        //             substringCount[subString]++;
        //         }
        //         else{
        //             break;
        //         }
        //     }
        // }
        // int length = -1;
        // for (auto subStr : substringCount) {
        //     if (subStr.second >= 3) {
        //         int temp = subStr.first.length();
        //         if (temp > length) {
        //             length = temp;
        //         }
        //     }
        // }
        // return length;

        // m-2 O(n^2)

        // map<pair<char,int>,int>mp;
        //  for (int i = 0; i < s.size(); i++) {
        //     char ch = s[i];
        //     int length =0;
        //     for (int j = i; j < s.size(); j++) {
        //         if (ch==s[j]) {
        //            length++;
        //            mp[{ch,length}]++;
        //         }
        //         else{
        //             break;
        //         }
        //     }
        // }
        // int ans =-1;
        // for (auto &it : mp) {
        //     if(it.second>=3){
        //         ans = max(ans,it.first.second);
        //     }
        // }
        // return ans;

        //m-3 - O(n)

        int n = s.size();
        vector<vector<int>> table(26, vector<int>(n + 1, 0));
        int length = 0;
        char prev_char = s[0];
        for (int i = 0; i < n; i++) {
            char curr_char = s[i];
            if (curr_char == prev_char) {
                length += 1;
                table[curr_char - 'a'][length] +=1;
            } else {
                length = 1;
                prev_char = curr_char;
                table[curr_char - 'a'][length] +=1;
            }
        }
        int result = -1;
        for (int i = 0; i < 26; i++) {
            int cumSum = 0;
            for (int j = n; j >= 1; j--) {
                cumSum += table[i][j];
                if (cumSum >= 3) {
                    result = max(result, j);
                    break;
                }
            }
        }
        return result;
    }
};
int main(){

 return 0;
}