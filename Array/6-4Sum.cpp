
#include <vector>
using namespace std;

/**
 * Given an array nums of n integers and an integer target, 
 * are there elements a, b, c, and d in nums such that a + b + c + d = target? 
 * Find all unique quadruplets in the array which gives the sum of target.
 * Note:The solution set must not contain duplicate quadruplets.
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        vector<int> quadruplet;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 3; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            if(nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if(nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;
            for(int j = i + 1; j < n - 2; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                if(nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if(nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;
                int start = j + 1, end = n - 1;
                while(start < end) {
                    int sum = target - nums[i] - nums[j];
                    if(nums[start] + nums[end] > sum) {
                        end--;
                    } else if(nums[start] + nums[end] < sum) {
                        start++;
                    } else {
                        quadruplet.clear();
                        quadruplet.push_back(nums[i]);
                        quadruplet.push_back(nums[j]);
                        quadruplet.push_back(nums[start]);
                        quadruplet.push_back(nums[end]);
                        res.push_back(quadruplet);
                        start++;
                        end--;
                        while(start < end && nums[start] == nums[start - 1]) start++;
                        while(start < end && nums[end] == nums[end + 1]) end--;
                    }
                }
            }
        }
        return res;
    }
};
