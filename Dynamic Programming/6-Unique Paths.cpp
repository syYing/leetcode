
#include <vector>
using namespace std;

/**
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time. 
 * The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * How many possible unique paths are there?
 * Note: m and n will be at most 100.
 */

class Solution{
public:
    /**
     * Suppose the number of paths to arrive at a point (i, j) is denoted as P[i][j], 
     * it is easily concluded that P[i][j] = P[i - 1][j] + P[i][j - 1].
     */
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m, vector<int>(n, 1));
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
