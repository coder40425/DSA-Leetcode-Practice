/* Given two integers a and b, return the sum of the two integers without using the operators + and -.

Example 1:
Input: a = 1, b = 2
Output: 3
  
Example 2:
Input: a = 2, b = 3
Output: 5                */


/*
##APPROACH: (Bit Manipulation using XOR & AND)
1. Use XOR (^) to add a and b without carry.
2. Use AND (&) to find carry bits and left shift by 1.
3. Update a and b: set a = sum, b = carry.
4. Repeat until carry becomes 0 (b == 0). Final answer is in a.

       TIME COMPLEXITY: O(1)  (Max 32 iterations for 32-bit integers)
       SPACE COMPLEXITY: O(1) (Constant space, no extra memory)                          */

//my code
class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            // carry now contains common set bits of a and b
            unsigned carry = unsigned(a & b);     //used unsigned to safely shift carry bits from negative numbers without sign issues

            // sum of bits of a and b where at least one of the bits is not set
            a = a ^ b;

            // carry is shifted by one so that adding it to a gives the required sum
            b = carry << 1;
        }
        // when there is no carry, a contains the final sum
        return a;
    }
};
