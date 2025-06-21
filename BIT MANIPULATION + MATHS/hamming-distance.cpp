/* The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.

Example 1:
Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.
  
Example 2:           
Input: x = 3, y = 1
Output: 1                                    */

/*
##APPROACH:-
-We XOR between two numbers, bits that differ become 1.
-Then we count the no. Of set bits (1s) in XOR result.
-Each set bit indicates a position where x & y differ. 
-Total number of such bits is the Hamming Distance.

      TIME COMPLEXITY:- O(1)
      SPACE COMPLEXITY:- O(1)                                  */

class Solution {
public:
    int hammingDistance(int x, int y) {
       int xorVal= x^y;
       int count=0;
       while(xorVal){
        //check if last bit is 1
        count = count + (xorVal & 1);
        //shift right
        xorVal= xorVal>>1;
       }
       return count;
    }
};

/*
##ONE LINER APPROACH:- (Using built in function)
-Use __builtin_popcount() to count the number of set bits directly.
-This built-in function returns the count of 1s in the binary representation.

    TIME COMPLEXITY:- O(1)
    SPACE COMPLEXITY:- O(1)                                      */

class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x^y);
    }
};
