
#include <vector>
using namespace std;

/**
 * Given an array of integers nums sorted in ascending order, 
 * find the starting and ending position of a given target value.
 * our algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 */

class Solution{
public:
    // Find the first number which is greater than or equal to target.
    int firstIndex(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while(start <= end) {
            int mid = (start + end) / 2;
            if(nums[mid] >= target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int first = firstIndex(nums, target);
        int last = firstIndex(nums, target + 1) - 1;
        if(first != nums.size() && nums[first] == target) {
            res = {first, last};
        } else {
            res = {-1, -1};
        }
        return res;
    }
};
