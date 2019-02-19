
#include <vector>
using namespace std;

/**
 * Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
 * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 * Note: You may not slant the container and n is at least 2.
 */

class Solution{
public:
    /**
     * We initialize i and j to first and last line, meaning the widest container.
     * All other containers are less width thus would need a higher water level in order to hold more water.
     * The smaller one of the two lines doesn't support a higher water level so can be removed.
     */
    int maxArea(vector<int>& height) {
        int water = 0;
        int i = 0, j = height.size() - 1;
        while(i < j) {
            water = max(water, (j - i) * min(height[i], height[j]));
            if(height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return water;
    }
};