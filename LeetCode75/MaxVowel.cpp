/* Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
 * 
 * Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
 */

class Solution {
public:
    int maxVowels(string s, int k) {
        int max_vowel_count = 0;
        for (int i = 0 ; i < k ; i++)
        {
            if (isVowels(s[i]))
                max_vowel_count++;
        }

        int temp_vowel_count = max_vowel_count;
        bool is_left_char_vowel;
        bool is_right_char_vowel;
        for (int i = k ; i < s.size() ; i++)
        {   
            is_left_char_vowel =  isVowels(s[i-k]);
            is_right_char_vowel = isVowels(s[i]);
            if (is_right_char_vowel == is_left_char_vowel) continue;
            if (is_right_char_vowel && !is_left_char_vowel) temp_vowel_count++;
            if (!is_right_char_vowel && is_left_char_vowel) temp_vowel_count--;
            if (temp_vowel_count > max_vowel_count) max_vowel_count = temp_vowel_count;
        }

        return max_vowel_count;
    }
    bool isVowels (char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

#if 0
思路 : same as Maximum Average Subarray
#endif
