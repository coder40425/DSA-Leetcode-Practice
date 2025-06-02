/* You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.

There are two types of logs:

Letter-logs: All words (except the identifier) consist of lowercase English letters.
Digit-logs: All words (except the identifier) consist of digits.
Reorder these logs so that:

The letter-logs come before all digit-logs.
The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
The digit-logs maintain their relative ordering.
Return the final order of the logs.


Example 1:
Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
Explanation:
The letter-log contents are all different, so their ordering is "art can", "art zero", "own kit dig".
The digit-logs have a relative order of "dig1 8 1 5 1", "dig2 3 6".
  
Example 2:
Input: logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]


APPROACH:
-SPLIT THE LOG INTO TWO PARTS: IDENTIFIER → FIRST WORD, CONTENT → EVERYTHING AFTER THE SPACE

-CHECK THE FIRST CHARACTER OF THE CONTENT TO SEE IF IT’S A DIGIT OR A LETTER

-COMPARISON LOGIC:

   IF BOTH ARE LETTER LOGS, SORT THEM BY CONTENT; IF CONTENTS ARE SAME, USE IDENTIFIER

   IF ONE IS LETTER AND ONE IS DIGIT → LETTER LOG GOES FIRST

   IF BOTH ARE DIGIT LOGS → KEEP THEM IN ORIGINAL ORDER

-USE STABLE_SORT SO DIGIT LOGS DON’T GET SHUFFLED.


  TIME COMPLEXITY:- O(NLOGN * M)   (N = NO. OF LOGS, M = AVG. LENGTH OF A LOG (IDENTIFIER + CONTENT)) 
                                    [SORTING -> O(NLOGN), COMPARISON -> O(M)]
  SPACE COMPLEXITY:- O(N)                                                                                                     */



class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        // Custom comparator for sorting
        auto cmp = [](const string &log1, const string &log2) {
            // Split into identifier and content
            int idx1 = log1.find(' ');
            string id1 = log1.substr(0, idx1);
            string content1 = log1.substr(idx1 + 1);

            int idx2 = log2.find(' ');
            string id2 = log2.substr(0, idx2);
            string content2 = log2.substr(idx2 + 1);

            // Check if they are digit-logs
            bool isDigit1 = isdigit(content1[0]);
            bool isDigit2 = isdigit(content2[0]);

            // Case 1: both are letter-logs
            if (!isDigit1 && !isDigit2) {
                if (content1 != content2)
                    return content1 < content2; // sort by content
                return id1 < id2; // tie-breaker: sort by id
            }

            // Case 2: one is letter-log, one is digit-log
            if (!isDigit1 && isDigit2)
                return true;  // letter-log comes first
            if (isDigit1 && !isDigit2)
                return false; // digit-log comes later

            // Case 3: both are digit-logs → keep original order
            return false;
        };

        // Use stable_sort to preserve digit-log order
        stable_sort(logs.begin(), logs.end(), cmp);
        return logs;
    }
};
 
