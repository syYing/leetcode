
#include <string>
using namespace std;

/**
 * Given a string s, find the longest palindromic substring in s. 
 * You may assume that the maximum length of s is 1000.
 */

class Solution {
public:
    /**
     * We observe that a palindrome mirrors around its center. 
     * Therefore, a palindrome can be expanded from its center, and there are only (2n - 1) such center.
     */
    int expandAroundCenter(string s, int left, int right) {
        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
    
    string longestPalindrome(string s) {
        if(s.length() == 0) return "";
        int start = 0, end = 0, maxLen = 0;
        for(int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);
            if(len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
                maxLen = end - start + 1;
            }
        }
        return s.substr(start, maxLen);
    }
};
