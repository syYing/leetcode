
#include <vector>
#include <map>
using namespace std;

/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 */

class Solution {
public:
    /**
     * The basic idea is to maintain a hash table for each num in nums, 
     * using num as key and its index(0-based) as value.
     * For each num, search for (target - num) in the hash table.
     * If it is found and is not the same element as num, then we are done.
     * Note that each time before we add num to map, we search for (target - num) first,
     * so we will not hit the same element.
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> index;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            int j = target - nums[i];
            if(index.find(j) != index.end()) {
                ans.push_back(index[j]);
                ans.push_back(i);
                break;
            }
            index[nums[i]] = i;
        }
        return ans;
    }
};
