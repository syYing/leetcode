
#include <vector>
#include <string>
using namespace std;

/**
 * Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
 * You have the following 3 operations permitted on a word:
 * Insert a character, Delete a character, Replace a character.
 */

class Solution {
public:
    /**
     * We define the state dp[i][j] to be the minimum number of operations to convert word1[0..i) to word2[0..j).
     * For the base case, that is, to convert a string to an empty string, 
     * the mininum number of operations (deletions) is just the length of the string. So we have dp[i][0] = i and dp[0][j] = j.
     * For the general case to convert word1[0..i) to word2[0..j), we break this problem down into sub-problems. 
     * Suppose we have already known how to convert word1[0..i - 1) to word2[0..j - 1) (dp[i - 1][j - 1]), 
     * if word1[i - 1] == word2[j - 1], then no more operation is needed and dp[i][j] = dp[i - 1][j - 1].
     * If word1[i - 1] != word2[j - 1], we need to consider three cases.
     * 1. Replace word1[i - 1] by word2[j - 1] (dp[i][j] = dp[i - 1][j - 1] + 1);
     * 2. If word1[0..i - 1) = word2[0..j) then delete word1[i - 1] (dp[i][j] = dp[i - 1][j] + 1);
     * 3. If word1[0..i) + word2[j - 1] = word2[0..j) then insert word2[j - 1] to word1[0..i) (dp[i][j] = dp[i][j - 1] + 1).
     */
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        for(int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }
        return dp[m][n];
    }
};
