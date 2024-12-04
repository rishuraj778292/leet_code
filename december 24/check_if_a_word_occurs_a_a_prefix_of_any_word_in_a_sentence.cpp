/*
1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence

Given a sentence that consists of some words separated by a single space, and a searchWord, check if searchWord is a prefix of any word in sentence.

Return the index of the word in sentence (1-indexed) where searchWord is a prefix of this word. If searchWord is a prefix of more than one word, return the index of the first word (minimum index). If there is no such word return -1.

A prefix of a string s is any leading contiguous substring of s.

 

Example 1:

Input: sentence = "i love eating burger", searchWord = "burg"
Output: 4
Explanation: "burg" is prefix of "burger" which is the 4th word in the sentence.
Example 2:

Input: sentence = "this problem is an easy problem", searchWord = "pro"
Output: 2
Explanation: "pro" is prefix of "problem" which is the 2nd and the 6th word in the sentence, but we return 2 as it's the minimal index.
Example 3:

Input: sentence = "i am tired", searchWord = "you"
Output: -1
Explanation: "you" is not a prefix of any word in the sentence.
 

Constraints:

1 <= sentence.length <= 100
1 <= searchWord.length <= 10
sentence consists of lowercase English letters and spaces.
searchWord consists of lowercase English letters.
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int i = 0, j = 0, k = 1;
        while (j < sentence.size() && i < sentence.size()) {
            // check first letter of word match
            if (sentence[i] == searchWord[0]) {
                //if match then check for word match
                if (sentence.substr(i, searchWord.length()) == searchWord){
                    // if word match then check its is a perfix
                    if(i==0 || sentence[i-1]==' '){
                        // and if it is a orefix return word position
                        return k;
                    }
                }
                //if word not match then check further
                else{
                    i++;
                }
            } 
            // going to next word
            else {
                while (sentence[j] != ' ') {
                    if(j>sentence.size()-1){
                        break;
                    }
                    j++;
                }

                k++; // increase word position count after every newword
                i = j++ + 1;
            }
        }
        // aftre traversing all  the sentences if prefix is not found then return -1;
        return -1;
    }
};
int main(){

 return 0;
}