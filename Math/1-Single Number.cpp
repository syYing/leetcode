
#include <vector>
using namespace std;

/**
 * Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 * Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */

class Solution {
public:
    /**
     * If we take XOR of zero and some bits, it will return that bit.
     * If we take XOR of two same bits, it will return 0.
     * So we can XOR all bits together to find the unique number.
     */
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int num : nums) {
            ans ^= num;
        }
        return ans;
    }
};
