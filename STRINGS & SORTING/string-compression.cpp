/* Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

 
Example 1:
Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
  
Example 2:
Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.
  
Example 3:
Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".


APPROACH:
-WE WILL DO IT USING TWO POINTERS. ('i' TO WRITE & 'j' TO READ)
-INITIALISE COUNT WITH 1.
-TRAVERSE WITH "j" AND INCREASE COUNT EVERYTIME A CHARACTER REPEATS IN THE ARRAY.
-WHEN IT STOPS REPEATING, WRITE THAT CHARACTER AT INDEX "i" AND INCREASE "i". (i++)
-IF COUNT OF THAT CHARACTER IS GREATER THAN 1, THEN INITIALISE A STRING CNTSTR AND USE TO_STRING(COUNT) TO CONVERT INTEGER COUNT TO STRING.
-AFTER THAT, WRITE THE COUNT OF THAT CHARACTER.
-WHEN LOOP ENDS, RETURN "i" WHICH WILL BE THE NEW LENGTH OF THE ARRAY.


   TIME COMPLEXITY- O(N)
   SPACE COMPLEXITY-O(1)  
                                                                                            */



class Solution {
public:
    int compress(vector<char>& chars) {
    int i = 0;               // write pointer
    int count = 1;           // count of current character

    for (int j = 1; j <= chars.size(); j++) {
        if (j < chars.size() && chars[j] == chars[j - 1]) {
            count++;         // same character, increment count
        } else {
            chars[i] = chars[j - 1]; 
            i++; // write the character

            if (count > 1) {
                string cntStr = to_string(count);
                for (char c : cntStr) {
                    chars[i] = c;
                    i++;     // write the digits of count
                }
            }

            count = 1;       // reset count for next character
        }
    }

    return i; // length of the compressed array
}
};
 
