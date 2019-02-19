
#include <vector>
using namespace std;

/**
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
 * Find all unique triplets in the array which gives the sum of zero.
 * Note:The solution set must not contain duplicate triplets.
 */

class Solution{
public:
    /**
     * 假设升序数列a，对于一组解ai,aj, 另一组解ak,al
     * 必然满足 il 或 i>k j<l, 因此我们可以用两个指针，初始时指向数列两端
     * 指向数之和大于目标值时，右指针向左移使得总和减小，反之左指针向右移
     * Assume a is an asending array, for two sets of solutions like [ai, aj], [ak, al], they inevitably staified i < k < l < j.
     * Thus we can use two pointers to solve this qestion, they initially point the begin and the end of array.
     * If sum of the two pointed number is greater than target, right pointer move to the left in order to reduce sum,
     * otherwise, left pointer move to the right.
     */
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int start = i + 1, end = nums.size() - 1;
            int sum = nums[i] + nums[start] + nums[end];
            if(start > i + 1 && nums[start] == nums[start - 1]) {
                start++;
                continue;
            }
            if(sum > 0) {
                end--;
            } else if(sum < 0) {
                start++;
            } else {
                vector<int> triplet {nums[i], nums[start], nums[end]};
                res.push_back(triplet);
                start++;
            }
        }
        return res;
    }
};
