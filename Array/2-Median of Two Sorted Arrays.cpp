
#include <iostream>
#include <vector>
using namespace std;

/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * You may assume nums1 and nums2 cannot be both empty.
 */

class Solution {
public:
    /**
     * For an ordered array of length n, if n is odd, its median is the (n / 2 + 1) number,
     * otherwise, its median is (the (n / 2) number + the (n / 2 + 1) number) / 2.
     * If we can find the Kth number in an ordered array, problem solved.
     * Assume we have two arrays, A and B.
     * If A[k / 2] > B[k / 2] or (k / 2) is greater than the length of A, Kth number must not be in the front (k / 2) of B,
     * so we can delete the front (k / 2) numbers of B and find the (k - k / 2)th number in the remaining arrays.
     */
    double findKth(vector<int>& A, vector<int>& B, int indexA, int indexB, int k) {
        if(indexA >= A.size()) {
            return B[indexB + k - 1];
        }
        if(indexB >= B.size()) {
            return A[indexA + k - 1];
        }
        // k == 1 means that ans is the minimum of the remaining arrays.
        if(k == 1) {
            return min(A[indexA], B[indexB]);
        }
        int keyA = indexA + k / 2 - 1 >= A.size() ? INT_MAX : A[indexA + k / 2 - 1];
        int keyB = indexB + k / 2 - 1 >= B.size() ? INT_MAX : B[indexB + k / 2 - 1];
        if(keyA > keyB) {
            return findKth(A, B, indexA, indexB + k / 2, k - k / 2);
        } else {
            return findKth(A, B, indexA + k / 2, indexB, k - k / 2);
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = nums1.size() + nums2.size();
        double ans;

        if(sum & 1) {
            ans = findKth(nums1, nums2, 0, 0, sum / 2 + 1);
        } else {
            ans = (findKth(nums1, nums2, 0, 0, sum / 2) + findKth(nums1, nums2, 0, 0, sum / 2 + 1)) / 2.0;
        }

        return ans;
    }
};
