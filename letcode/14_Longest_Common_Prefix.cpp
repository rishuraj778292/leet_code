/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".



Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string longestCommonPrefix(vector<string> &strs)
{
    /*   my approach

    string str = "";
    string ans = strs[0];
    for (int i = 0; i < strs.size() - 1; i++)
    {
        int f = 0;
        int s = 0;
        string first = strs[i];
        string second = strs[i + 1];

        while (f < first.size() && s < second.size())
        {
            if (first[f] == second[s])
            {
                str += first[f];
                f++;
                s++;
            }
            else
            {
                break;
            }
        }
        if (ans.size() > str.size())
        {
            ans = str;
        }
        str = "";
    }

    return ans;
    */

    // beeter approach
    sort(strs.begin(), strs.end());
    string ans = "";
    string first = strs[0];
    int a = strs.size();
    string last = strs[a - 1];
    for (int i = 0; i < first.size(); i++)
    {
        if (first[i] == last[i])
        {
            ans += first[i];
        }
        else
        {
            break;
        }
    }

    return ans;
}

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "longest prefix is: " << longestCommonPrefix(strs) << endl;
    return 0;
}