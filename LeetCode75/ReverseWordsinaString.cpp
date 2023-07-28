/ * Given an input string s, reverse the order of the words.
  * 
  * A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
  * 
  * Return a string of the words in reverse order concatenated by a single space.

  * Note that s may contain leading or trailing spaces or multiple spaces between two words. 
  * The returned string should only have a single space separating the words. Do not include any extra spaces.
  */

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string a_word = "";
        // read through all char then put into words vector
        for (char c : s)
        {
            if (c != ' ')
               a_word += c;
            else if (!a_word.empty ())
            {
                words.push_back(a_word);
                a_word = "";
            }
        }
        if (!a_word.empty ())
        {
            words.push_back(a_word);
            a_word = "";
        }

        // reverse then put them together to reverse string
        reverse(words.begin(), words.end());
        string reverse_s = "";
        for (auto word : words)
        {
            reverse_s += (word + " ");
        }
        reverse_s.pop_back();
        return reverse_s;
    }
};

#if 0
暫且暴力解o-o
#endif
