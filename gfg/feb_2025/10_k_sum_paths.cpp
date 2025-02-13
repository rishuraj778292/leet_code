/*
K Sum Paths
Difficulty: MediumAccuracy: 44.73%Submissions: 112K+Points: 4
Given a binary tree and an integer k, determine the number of downward-only paths where the sum of the node values in the path equals k. A path can start and end at any node within the tree but must always move downward (from parent to child).

Examples:

Input: k = 7   

Output: 3
Explanation: The following paths sum to k 
 
Input: k = 3

Output: 2
Explanation:
Path 1 : 1 -> 2 (Sum = 3)
Path 2 : 3 (Sum = 3)


Constraints:

1 ≤ number of nodes ≤ 104
-100 ≤ node value ≤ 100
-109 ≤ k ≤ 109

*/

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  // m-1 O(n^2)->  traverse all node and find for each
  int countAllpathFromNode(Node*root,int k,int sum){
      if(root==NULL){
          return 0;
      }
      
      int pathCount=0;
      
      sum += root->data;
      
      if(sum==k){
          pathCount++;
      }
      
      pathCount += countAllpathFromNode(root->left,k,sum);
      pathCount += countAllpathFromNode(root->right,k,sum);
      
      return pathCount;
      
      
  }
    int countAllpath(Node *root, int k){
        if(root==NULL){
            return 0;
        }
        
        int path = countAllpathFromNode(root,k,0);
        
        path +=  countAllpath(root->left, k);
        path += countAllpath(root->right, k);
        return path;
        
    }
    
    // method -2 -> prefix sum
    int countpath(Node *root, int k,unordered_map<int,int>&hash,int sum){
        if(root==NULL){
            return 0;
        }
        
        sum = sum+root->data;
        int path=0;
        if(sum==k){
            path++;
        }
        int diff=sum-k;
        
        
        path+=hash[diff];
        hash[sum]++;
        
        path+=countpath(root->left,k,hash,sum);
        path+=countpath(root->right,k,hash,sum);
        hash[sum]--;
        return path;
        
        
    }
    int sumK(Node *root, int k) {
        // code here
        // method -1
        
        //return countAllpath(root,k);
        
        // method - 2
        unordered_map<int,int>hash;
        return countpath(root, k,hash,0);
        
        
    }
};

//{ Driver Code Starts.

int main() {
    string tc;
    getline(cin, tc);
    int t = stoi(tc);

    while (t--) {
        string s, ch;
        getline(cin, s);
        Node *root = buildTree(s);

        string key;
        getline(cin, key);
        int k = stoi(key);
        Solution ob;
        cout << ob.sumK(root, k) << "\n";
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends