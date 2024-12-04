/*
593. Valid Square

Medium

Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.

The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.

A valid square has four equal sides with positive length and four equal angles (90-degree angles).



Example 1:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: true
Example 2:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
Output: false
Example 3:

Input: p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
Output: true


Constraints:

p1.length == p2.length == p3.length == p4.length == 2
-104 <= xi, yi <= 104
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double findDist(vector<int> &p1, vector<int> &p2)
    {
        double dist = sqrt((pow((p2[0] - p1[0]), 2) + pow((p2[1] - p1[1]), 2)));
        return dist;
    }
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {

        set<double> dist;
        dist.insert(findDist(p1, p2));
        dist.insert(findDist(p1, p3));
        dist.insert(findDist(p1, p4));

        dist.insert(findDist(p2, p3));
        dist.insert(findDist(p2, p4));

        dist.insert(findDist(p3, p4));
        for (auto val : dist)
        {
            if (val == 0)
            {
                return false;
            }
        }
        if (dist.size() == 2)
        {
            return true;
        }
        else
        {
            return false;
            ;
        }
    }
};
int main()
{

    return 0;
}