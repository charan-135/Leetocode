#include <vector>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        std::vector<int> merged;
        
        int p1 = 0, p2 = 0;
        

        while (p1 < n && p2 < m) {
            if (nums1[p1] <= nums2[p2]) {
                merged.push_back(nums1[p1]);
                p1++;
            } else {
                merged.push_back(nums2[p2]);
                p2++;
            }
        }
        

        while (p1 < n) {
            merged.push_back(nums1[p1]);
            p1++;
        }
        
        while (p2 < m) {
            merged.push_back(nums2[p2]);
            p2++;
        }
        
      
        int totalSize = merged.size();
        if (totalSize % 2 != 0) {
            return merged[totalSize / 2];
        } else {
            return (merged[totalSize / 2 - 1] + merged[totalSize / 2]) / 2.0;
        }
    }
};