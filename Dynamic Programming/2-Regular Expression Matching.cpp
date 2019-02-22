
#include <vector>
#include <string>
using namespace std;

/**
 * Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * The matching should cover the entire input string (not partial).
 * Note: s could be empty and contains only lowercase letters a-z.
 *       p could be empty and contains only lowercase letters a-z, and characters like . or *.
 */

class Solution{
public:
    /**
     * We define dp[i][j] to be true if s[0..i) matches p[0..j) and false otherwise. The state equations will be:
     * dp[i][j] = dp[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
     * dp[i][j] = dp[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 time;
     * dp[i][j] = dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 time.
     */
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(p[j - 1] != '*') {
                    dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                } else {
                    dp[i][j] = dp[i][j - 2] || (i && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                }
            }
        }
        return dp[m][n];
    }
};
