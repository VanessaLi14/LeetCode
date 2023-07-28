/* Given a string s, reverse only all the vowels in the string and return it.
 * 
 * The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
 */

class Solution {
public:
    string reverseVowels(string s) {
        int left_index = 0;
        int right_index = s.size() - 1;
        bool isLeftVowels = false;
        bool isRightVowels = false;
        while (left_index < right_index)
        {
            // continue find the vowels
            while ((left_index < right_index) && !(isLeftVowels = isVowels(s[left_index])))
                left_index ++;
            while ((left_index < right_index) && !(isRightVowels = isVowels(s[right_index])))
                right_index --;  

            // found left and found right -> swap them!
            swap (s[left_index], s[right_index]);
            left_index ++;
            right_index --;
        }
        return s;
    }
    bool isVowels (const char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
        || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }
    
};

#if 0
思路 : 
string s = "string"
            ^    ^
   left_index    right_index
兩個位置從外找到裡面，一旦從左邊找到就等換右邊找，
找到並且左邊還是左邊，右邊還是右邊，
就可以去做交換位置並且往內一格。
#endif
