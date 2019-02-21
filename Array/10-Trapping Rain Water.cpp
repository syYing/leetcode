
#include <vector>
using namespace std;

/**
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, 
 * compute how much water it is able to trap after raining.
 */

class Solution{
public:
    /**
     * Find maximum height of bar from the left end upto an index i in the array.
     * Find maximum height of bar from the right end upto an index i in the array.
     * Iterate over the array and update ans.
     */
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        vector<int> maxLeft(n), maxRight(n);
        maxLeft[0] = height[0];
        for(int i = 1; i < n; i++) {
            maxLeft[i] = max(maxLeft[i - 1], height[i]);
        }
        maxRight[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], height[i]);
        }
        for(int i = 1; i < n - 1; i++) {
            ans += min(maxLeft[i], maxRight[i]) - height[i];
        }
        return ans;
    }
};