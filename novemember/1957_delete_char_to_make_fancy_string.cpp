/*
1957. Delete Characters to Make Fancy String

A fancy string is a string where no three consecutive characters are equal.

Given a string s, delete the minimum possible number of characters from s to make it fancy.

Return the final string after the deletion. It can be shown that the answer will always be unique.

 

Example 1:

Input: s = "leeetcode"
Output: "leetcode"
Explanation:
Remove an 'e' from the first group of 'e's to create "leetcode".
No three consecutive characters are equal, so return "leetcode".
Example 2:

Input: s = "aaabaaaa"
Output: "aabaa"
Explanation:
Remove an 'a' from the first group of 'a's to create "aabaaaa".
Remove two 'a's from the second group of 'a's to create "aabaa".
No three consecutive characters are equal, so return "aabaa".
Example 3:

Input: s = "aab"
Output: "aab"
Explanation: No three consecutive characters are equal, so return "aab".
 

Constraints:

1 <= s.length <= 105
s consists only of lowercase English letters.
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string makeFancyString(string s) {
        //     if(s.size()<=2){
        //         return s;
        //     }
        //
        //    int count = 0;
        //    int i = 1;
        //    while(i<=s.size()-1){
        //     if(s[i-1]==s[i]){
        //         count++;
        //         i++;
        //         if(count>1){
        //             i--;
        //             s.erase(s.begin()+i);
        //         }
        //     }
        //     else{
        //         count = 0;
        //         i++;
        //     }
        //    }
        //    return s;

        // m- 2

        string newString = "";
        pair<char, int> count{'a', 0};
        for (int i = 0; i < s.size(); i++) {
            if (count.first != s[i]) {
                count.first = s[i];
                count.second = 1;
                newString += s[i];
            } else {
                if (count.second < 2) {
                    count.second++;
                    newString += s[i];
                }
            }
        }
        return newString;
    }
};
int main(){

 return 0;
}