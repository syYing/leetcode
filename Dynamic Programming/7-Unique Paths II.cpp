
#include <vector>
using namespace std;

/**
 * A robot is located at the top-left corner of a m x n grid.
 * The robot can only move either down or right at any point in time. 
 * The robot is trying to reach the bottom-right corner of the grid.
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * Note: m and n will be at most 100.
 */

class Solution {
public:
    /**
     * 1. If the first cell obstacleGrid[0,0] contains 1, we would return the number of ways as 0.
     * 2. Iterate the first row. If a cell originally contains a 1, set the value of that cell to 0. 
     * Otherwise, set it to the value of previous cell obstacleGrid[i,j] = obstacleGrid[i,j-1].Same as the first column.
     * 3. Iterate through the array starting from cell obstacleGrid[1,1]. 
     * If a cell originally doesn't contain any obstacle, then obstacleGrid[i,j] = obstacleGrid[i-1,j] + obstacleGrid[i,j-1].
     * If a cell contains an obstacle set it to 0 and continue.
     */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long long> > dp(m, vector<long long>(n, 1));
        if(obstacleGrid[0][0] == 1) {
            return 0;
        }
        for(int i = 1; i < m; i++) {
            if(obstacleGrid[i][0] == 1) {
                dp[i][0] = 0;
            } else {
                dp[i][0] = dp[i - 1][0];
            }
        }
        for(int j = 1; j < n; j++) {
            if(obstacleGrid[0][j] == 1) {
                dp[0][j] = 0;
            } else {
                dp[0][j] = dp[0][j -  1];
            }
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return (int)dp[m - 1][n - 1];
    }
};
