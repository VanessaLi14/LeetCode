/* 
 * Description :
 * Given a string s, find the length of the longest substring without repeating characters.
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> dictionary; // <stringCharacter, nextID>
        map<char, int>::iterator it;
        int strLength = s.length ();
        int left = 0, right = 0;
        int ans = 0;
        
        for (right = 0 ; right < strLength ; right++) {
            // 如果在map中找到重複字元，將left移往在map中所記住的下個ID
            it = dictionary.find (s.at (right));
            if (it != dictionary.end ()) {
                left = std::max (dictionary[s[right]], left);
            }
            
            ans = std::max (ans, right - left + 1);
            // val為 : 如果找到重複字母，會從下個ID開始算
            dictionary [s[right]] = right + 1; 
        }
        
        return ans;
    }
};
