class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sorted;
        int i = 0, j = 0;
        int s1 = nums1.size(), s2 = nums2.size();
        while (i < s1 && j < s2) {
            if (nums1[i] < nums2[j]) {
                sorted.push_back(nums1[i]);
                i++;
            } else {
                sorted.push_back(nums2[j]);
                j++;
            }
        }
        while (i < s1) {
            sorted.push_back(nums1[i]);

            i++;
        }
        while (j < s2) {
            sorted.push_back(nums2[j]);
            j++;
        }

        if ((s1 + s2) % 2 != 0)
            return sorted[(s1 + s2) / 2];
        cout << sorted[(s1 + s2) / 2] << " " << sorted[(s1 + s2) / 2 - 1];
        return (double)(sorted[(s1 + s2) / 2] + sorted[(s1 + s2) / 2 - 1]) / 2;
    }
};