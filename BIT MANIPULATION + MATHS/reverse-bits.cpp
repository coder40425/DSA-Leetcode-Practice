/* Reverse bits of a given 32 bits unsigned integer.

Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. 
They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.

Example 1:
Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596,
              so return 964176192 which its binary representation is 00111001011110000010100101000000.                      */


/*
##APPROACH 1: (BITSET + STRING REVERSE)
1. Convert the number n into a 32-bit binary string using bitset<32>.
2. Reverse the binary string using reverse() from STL.
3. Convert the reversed string back into a number using bitset<32>.to_ulong().

  Time Complexity: O(32) → effectively O(1)
  Space Complexity: O(32) → effectively O(1) (constant auxiliary space for string and bitsets)            */

//my code 1
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // Step 1: Convert integer to binary string of 32 bits
        string s = bitset<32>(n).to_string();

        // Step 2: Reverse the string (i.e., reverse the bits)
        reverse(s.begin(), s.end());

        // Step 3: Convert reversed binary string back to number
        return bitset<32>(s).to_ulong();
    }
};

/*
##APPROACH 2: (BITWISE REVERSAL)
1. Initialize result res = 0, and process each of the 32 bits of input n.
2. In each iteration, left shift res, extract the last bit of n using n & 1, and OR it into res.
3. Right shift n to move to the next bit; repeat this for all 32 bits.
 
Time Complexity: O(32) → O(1) (Fixed 32-bit loop)
Space Complexity: O(1) (Only one variable res used)                                   */

//my code 2
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;

        for (int i = 0; i < 32; ++i) {
            res <<= 1;         // Step 2a: Left shift res to make space
            res |= (n & 1);    // Step 2b: Extract last bit of n and add it to res
            n >>= 1;           // Step 3: Move to next bit of n
        }

        return res;
    }
};
