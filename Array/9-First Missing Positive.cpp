
#include <vector>
using namespace std;

/**
 * Given an unsorted integer array, find the smallest missing positive integer.
 * Note:Your algorithm should run in O(n) time and uses constant extra space.
 */

class Solution {
public:
    /**
     * Given a number in the array:
     * if it is non-positive, ignore it;
     * if it is positive, say we have nums[i] = x, we know it should be in slot nums[x - 1].
     * That is to say, we can swap nums[i] with nums[x - 1] so as to place x into the right place.
     * We need to keep swaping until all numbers are either non-positive or in the right place.
     */
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            // exchange conditions:
            // 1: nums[i] is in the range;
            // 2: nums[i] > 0;
            // 3: The target is different;
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};