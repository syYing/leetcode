
#include <vector>
using namespace std;

/**
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 */

class Solution {
public:
    // Binary search
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int res = -1, start = 0, end = n - 1;
        while(start <= end) {
            int mid = (start + end) / 2;
            if(nums[mid] > target) {
                if(nums[mid] > nums[end] && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else if(nums[mid] < target) {
                if(nums[mid] < nums[start] && target >= nums[start]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                res = mid;
                break;
            }
        }
        return res;
    }
};
