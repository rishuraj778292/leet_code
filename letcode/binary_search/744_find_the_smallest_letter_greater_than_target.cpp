/*
744. Find Smallest Letter Greater Than Target

You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.

Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

 

Example 1:

Input: letters = ["c","f","j"], target = "a"
Output: "c"
Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.
Example 2:

Input: letters = ["c","f","j"], target = "c"
Output: "f"
Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.
Example 3:

Input: letters = ["x","x","y","y"], target = "z"
Output: "x"
Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].
 

Constraints:

2 <= letters.length <= 104
letters[i] is a lowercase English letter.
letters is sorted in non-decreasing order.
letters contains at least two different characters.
target is a lowercase English letter.
*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // store first character as a answer kyunki according to question agr
        // koi smallest character i.e greater than target to array ka first
        // character ko return krna hai
        int ans = letters[0];
        int s = 0;
        int e = letters.size() - 1;

        while (s <= e) {
            // mid ko calculate kr lenge
            int mid = (s + e) / 2;

            // agr letters[mid] km ya equal rhega target ko toh hm s ko update
            // kr denge
            if (letters[mid] == target || letters[mid] < target) {
                s = mid + 1;
            }
            // aur agr bda rha to ans store kr lenge aur end ko update kr denge
            else {
                ans = letters[mid];
                e = mid - 1;
            }
        }
        // return the answer
        return ans;
    }
};