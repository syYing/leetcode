
#include <string>
#include <vector>
using namespace std;

/**
 * Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * The matching should cover the entire input string (not partial).
 * Note: s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters like ? or *.
 */

class Solution {
public:
    /**
     * We define the state dp[i][j] to be whether s[0..i) matches p[0..j). The state equations are as follows:
     * if p[j - 1] != '*', dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
     * if p[j - 1] == '*', dp[i][j] = dp[i][j - 1] || dp[i - 1][j].
     */
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for(int i = 0; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(p[j - 1] == '*') {
                    dp[i][j] = (i && dp[i - 1][j]) || dp[i][j - 1];
                } else {
                    dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
                }
            }
        }
        return dp[m][n];
    }
};
