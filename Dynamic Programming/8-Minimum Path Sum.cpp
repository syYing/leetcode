
#include <vector>
using namespace std;

/**
 * Given a m x n grid filled with non-negative numbers, 
 * find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 * Note: You can only move either down or right at any point in time.
 */

class Solution {
public:
    /**
     * Suppose the minimum path sum of arriving at point (i, j) is dp[i][j], 
     * then the state equation is dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j].
     */
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 1; i < m; i++) {
            grid[i][0] += grid[i - 1][0];
        }
        for(int j = 1; j < n; j++) {
            grid[0][j] += grid[0][j - 1];
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};
