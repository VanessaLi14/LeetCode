/* You are given two strings word1 and word2. 
 * Merge the strings by adding letters in alternating order, starting with word1. 
 * If a string is longer than the other, append the additional letters onto the end of the merged string.
 */

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged_string = "";
      
        // pointers that point to the first char of word
        const char *word1_ptr = word1.c_str(); 
        const char *word2_ptr = word2.c_str();
      
        do
        {
            // check if is pointed comething, then put char into merged_string 
            if (*word1_ptr != '\0')
            {
                merged_string += *word1_ptr;
                word1_ptr ++;
            }
          
            // same as above
            if (*word2_ptr != '\0')
            {
                merged_string += *word2_ptr;
                word2_ptr ++;
            }
            
        }  // check if both pointed to the end of word 
        while (*word1_ptr != '\0' || *word2_ptr != '\0');
      
        return merged_string;
    }
};
