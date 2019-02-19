
#include <vector>
using namespace std;

/**
 * Given an array nums of n integers and an integer target, 
 * find three integers in nums such that the sum is closest to target. 
 * Return the sum of the three integers. 
 * You may assume that each input would have exactly one solution.
 */

class Solution{
public:
    /**
     * Almost same solution with 3Sum.
     * Sort the array first, then loop with two pointers.
     * Update the closest result and the smallest diff in each loop.
     */
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            int start = i + 1, end = nums.size() - 1;
            while(start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if(sum > target) {
                    end--;
                } else if(sum < target){
                    start++;
                } else {
                    return target;
                }
                if(abs(sum - target) < diff) {
                    res = sum;
                }
                diff = min(diff, abs(sum - target));
            }
        }
        return res;
    }
};
