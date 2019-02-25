
#include <vector>
#include <string>
using namespace std;

/**
 * Given a string containing just the characters '(' and ')', 
 * find the length of the longest valid (well-formed) parentheses substring.
 */

class Solution{
public:
    /**
     * We make use of a dp array where ith element of dp represents the length of the longest valid substring ending at ith index.
     * We initialize the complete dp array with 0's.
     * The valid substrings must end with ')', thus, we update the dp array only when ')' is encountered.
     * To fill dp array we will check every two consecutive characters of the string and if
     * 1. s[i] = ')' and s[i - 1] = '(' => dp[i] = dp[i - 2] + 2;
     * 2. s[i] = ')' and s[i - 1] = ')', if s[i - dp[i - 1] - 1] = '(' then dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2].
     */ 
    int longestValidParentheses(string s) {
        int n = s.length(), ans = 0;
        vector<int> dp(n, 0);
        for(int i = 1; i < n; i++) {
            if(s[i] == ')') {
                if(s[i - 1] == '(') {
                    dp[i] = i >= 2 ? dp[i - 2] + 2 : 2;
                } else if(i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
