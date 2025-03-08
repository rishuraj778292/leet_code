/*

Testcase
Testcase
Test Result
Code
1352. Product of the Last K Numbers
Solved
Medium
Topics
Companies
Hint
Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.

Implement the ProductOfNumbers class:

ProductOfNumbers() Initializes the object with an empty stream.
void add(int num) Appends the integer num to the stream.
int getProduct(int k) Returns the product of the last k numbers in the current list. You can assume that always the current list has at least k numbers.
The test cases are generated so that, at any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.

 

Example:

Input
["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]

Output
[null,null,null,null,null,null,20,40,0,null,32]

Explanation
ProductOfNumbers productOfNumbers = new ProductOfNumbers();
productOfNumbers.add(3);        // [3]
productOfNumbers.add(0);        // [3,0]
productOfNumbers.add(2);        // [3,0,2]
productOfNumbers.add(5);        // [3,0,2,5]
productOfNumbers.add(4);        // [3,0,2,5,4]
productOfNumbers.getProduct(2); // return 20. The product of the last 2 numbers is 5 * 4 = 20
productOfNumbers.getProduct(3); // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
productOfNumbers.getProduct(4); // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
productOfNumbers.add(8);        // [3,0,2,5,4,8]
productOfNumbers.getProduct(2); // return 32. The product of the last 2 numbers is 4 * 8 = 32 
 

Constraints:

0 <= num <= 100
1 <= k <= 4 * 104
At most 4 * 104 calls will be made to add and getProduct.
The product of the stream at any point in time will fit in a 32-bit integer.
 

Follow-up: Can you implement both GetProduct and Add to work in O(1) time complexity instead of O(k) time complexity?








editorial:-

Approach: Prefix Product
Intuition
We need to implement the ProductOfNumbers class initialized with an empty integer stream that supports two operations:

add(int num): Add num to the stream.
getProduct(int k): Return the product of the last k integers in the stream. It's guaranteed that the product of the last k integers would fit into a 32-bit integer.
While the problem seems simple, the constraints - especially the potential size of the stream - make it clear that a brute force solution won’t work. A brute force approach would involve iterating over the last k integers each time a query is made, but this would be inefficient given the constraints of the problem (the stream size and k are both bound by 4 * 10^4).

To think of an optimized approach, let’s first consider the add function in which we need to find the sum of the last k integers. A natural solution here is a prefix sum approach. Prefix sum refers to an array where each element at index i represents the sum of the elements in the original array from the beginning up to the i-th element. This allows us to efficiently compute the sum of any subarray by subtracting two prefix sums. More specifically, by storing the cumulative sum of all integers up to the current index in an array, we can quickly compute the sum of the last k integers by simply taking the difference between two prefix sums: prefixSum[size] - prefixSum[size - k]. This gives us the sum in constant time.

Now, let’s apply a similar idea for the product. Instead of maintaining a prefix sum, we can maintain a prefix product array. This array will store the product of all integers encountered in the stream up to the current index. When we need the product of the last k integers, we can calculate it in constant time using the formula prefixProduct[size] / prefixProduct[size - k], just like we did for the sum.

But there's one edge case here: the presence of a 0 in the stream complicates things. If we encounter a 0, it nullifies all the products that come after it. For example, if the last k integers include a 0, the product of those integers will always be 0, regardless of the other numbers. This creates an issue when trying to calculate the product of the last k integers, especially if the 0 occurred earlier in the stream, long before the last k elements.

To address this, we can reset the prefix product array whenever we encounter a 0. This ensures that once a 0 is encountered, the product calculation is reset, and any future products that involve the 0 will correctly result in 0. When the product array is reset, we initialize it with 1 to start fresh.

Now, when answering a query to return the product of the last k integers, we can check the size of the prefix product array. If the size is less than or equal to k, we know that the last k integers must include a 0, so we return 0. Otherwise, we simply compute the product using the formula prefixProduct[size] / prefixProduct[size - k].

Algorithm
Constructor - ProductOfNumbers()

Initialize the prefixProduct list with {1} to handle multiplication logic without special cases for the initial product.
Set size to 0 to indicate that the product list is initially empty.
Helper Function - add(int num)

If num == 0:
Reset the prefixProduct list to {1}.
Reset size to 0 to indicate an empty product list.
Otherwise:
Append the cumulative product of the current number by multiplying it with the last value in the prefixProduct list.
Increment size.
Helper Function - getProduct(int k)

If k > size:
Return 0 because this implies that a 0 had appeared within the last k elements, making the product 0.
Otherwise:
Return the result of dividing prefixProduct[size] by prefixProduct[size - k] to get the product of the last k elements.
Implementation

class ProductOfNumbers {
private:
    // Stores cumulative product of the stream
    vector<int> prefixProduct;
    int size = 0;

public:
    ProductOfNumbers() {
        // Initialize the product list with 1 to handle multiplication logic
        prefixProduct.push_back(1);
        size = 0;
    }

    void add(int num) {
        if (num == 0) {
            // If num is 0, reset the cumulative products since multiplication
            // with 0 invalidates previous products
            prefixProduct = {1};
            size = 0;
        } else {
            // Append the cumulative product of the current number with the last
            // product
            prefixProduct.push_back(prefixProduct[size] * num);
            size++;
        }
    }

    int getProduct(int k) {
        // Check if the requested product length exceeds the size of the valid
        // product list
        if (k > size) return 0;

        // Compute the product of the last k elements using division
        return prefixProduct[size] / prefixProduct[size - k];
    }
};


Complexity Analysis
Let n be the number of elements added to the ProductOfNumbers object using the add method, and let k be the parameter passed to the getProduct method.

Time Complexity: O(n)

add method:

When adding a number, the operation involves appending to the prefix_product list and updating the size. If the number is 0, the list is reset.
Appending to a list and resetting the list are both O(1) operations.
Therefore, the time complexity of the add method is O(1).
getProduct method:

The getProduct method involves a division operation to compute the product of the last k elements.

Division and accessing elements in a list are O(1) operations.

Therefore, the time complexity of the getProduct method is O(1).

Therefore the add method runs in O(1) time per operation, and the getProduct method also runs in O(1) time per operation. For n operations, the total time complexity is O(n).

Space Complexity: O(n)

The prefixProduct list stores the cumulative product of the numbers added. In the worst case, when no 0 is added, the list grows linearly with the number of elements added. Therefore, the space complexity is O(n).






*/

#include<bits/stdc++.h>
using namespace std;
class ProductOfNumbers {
    public:
       //vector<int>arr;
    
        vector<int>cummProduct;
        int n=0;
        ProductOfNumbers() {
            
        }
        
        // approach - 1
    
        // void add(int num) {
        //     arr.push_back(num);
        // }
        
        // int getProduct(int k) {
        //     int j=arr.size()-1;
        //     int to_stop = k;
        //     int result=1;
        //     while(to_stop){
        //         result *= arr[j--];
        //         to_stop--;
        //     }
        //     return result;
        // }
    
        // approach - 2
         void add(int num) {
            if(num==0){
                cummProduct.clear();
                n=0;
            }
            else if(!cummProduct.empty()){
                cummProduct.push_back(cummProduct[n-1]*num);
                n++;
            }
            else{
                cummProduct.push_back(num);
                n++;
            }
        }
        
        int getProduct(int k) {
            if(n==k){
                return cummProduct[n-1];
            }
            else if(n<k){
                return 0;
            }
            else{
                return (cummProduct[n-1]/cummProduct[n-k-1]);
            }
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */
int main(){

 return 0;
}