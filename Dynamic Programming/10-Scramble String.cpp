
#include <string>
using namespace std;

/**
 * Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
 * To scramble the string, we may choose any non-leaf node and swap its two children.
 * Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
 */

class Solution{
public:
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length()) {
            return false;
        }
        if(s1 == s2) {
            return true;
        }
        int len = s1.length();
        int table[26] = {0};
        for(int i = 0; i < len; i++) {
            table[s1[i] - 'a']++;
            table[s2[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++) {
            if(table[i] != 0) {
                return false;
            }
        }
        for(int i = 1; i < len; i++) {
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) {
                return true;
            }
            if(isScramble(s1.substr(0, i), s2.substr(len - i)) && isScramble(s1.substr(i), s2.substr(0, len - i))) {
                return true;
            }
        }
        return false;
    }
};
