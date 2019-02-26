
#include <vector>
using namespace std;

/**
 * Given an integer array nums, find the contiguous subarray (containing at least one number) 
 * which has the largest sum and return its sum.
 */

class Solution {
public:
    /**
     * The idea is to maintain a running maximum ans and a current summation sum.
     * When we visit each num in nums, add num to sum then update ans or reset sum to 0 if it becomes negative.
     */
    int maxSubArray(vector<int>& nums) {
        int sum = 0, ans = INT_MIN;
        for(int num : nums) {
            sum += num;
            ans = max(ans, sum);
            if(sum < 0) {
                sum = 0;
            }
        }
        return ans;
    }
};
