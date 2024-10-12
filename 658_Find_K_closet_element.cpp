/*
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b


Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]


Constraints:

1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104

*/

#include <iostream>
#include<vector>
using namespace std;

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    vector<int> ans;
    int i = 0;
    int j = arr.size() - 1;
    while (j - i + 1 != k)
    {
        if (abs(x - arr[i]) > abs(x - arr[j]))
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    for (int k = i; k <= j; k++)
    {
        ans.push_back(arr[k]);
    }
    return ans;
}

int main()

{
    vector<int>arr={1,2,3,4,5};
    int k =4;
    int x =3;
    vector<int>ans = findClosestElements(arr, k, x);
    for(auto val :ans){
        cout<<val<<" ";
    }

    return 0;
}