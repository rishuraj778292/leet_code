/*
1790. Check if One String Swap Can Make Strings Equal
Solved
Easy
Topics
Companies
Hint
You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

 

Example 1:

Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".
Example 2:

Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap.
Example 3:

Input: s1 = "kelb", s2 = "kelb"
Output: true
Explanation: The two strings are already equal, so no string swap operation is required.
 

Constraints:

1 <= s1.length, s2.length <= 100
s1.length == s2.length
s1 and s2 consist of only lowercase English letters.
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        // approach -1 -> O(n^2)
        /*
        if(s1==s2){
            return true;
        }
        for(int i=0;i<s1.size();i++){
            for(int j=0;j<s1.size();j++){
                swap(s1[i],s1[j]);
                if(s1==s2){
                    return true;
                }
                swap(s1[i],s1[j]);
            }
        }
        return false;
        */
        // approach-2 -> O(n)
        /*
        if (s1 == s2) {
            return true;
        }
        string diffchars1 = "";
        string diffchars2 = "";
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                diffchars1 += s1[i];
                diffchars2 += s2[i];
            }
        }
        reverse(diffchars2.begin(), diffchars2.end());
        cout << diffchars1 << " " << diffchars2;
        if (diffchars1 == diffchars2 && diffchars1.size() == 2 &&
            diffchars2.size() == 2) {
            return true;
        } else {
            return false;
        }
        
        */

        // approach - 3 --> best approach
        /*
         if (s1 == s2) {
            return true;
        }
        vector<int>diffPos;
        int diffCount=0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                diffCount++;
                if(diffCount>2){
                    return false;
                }
               diffPos.push_back(i);
            }
        }

        if(diffCount==2 && s1[diffPos[0]]==s2[diffPos[1]] && s1[diffPos[1]]==s2[diffPos[0]] ){
            return true;
        }
        else{
         return false;
        }
        */

        // approach-4 using hash map
        int hash1[26]={0};
        int hash2[26]={0};
        int diffCount=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                diffCount++;
                if(diffCount>2){
                    return false;
                }
            }
            hash1[s1[i]-'a']++;
            hash2[s2[i]-'a']++;
        }

        for(int j=0;j<26;j++){
            if(hash1[j]!=hash2[j]){
                return false;
            }
        }
        return true;
    }
};

int main(){

 return 0;
}