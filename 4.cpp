// 16ms, 9.6MB

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) {
            swap(m, n); swap(nums1, nums2); // guarantee that m <= n
        }
        if (m == 0) {
            if (n % 2 == 0)
                return (nums2[n/2]+nums2[n/2-1])*1.0/2;
            else
                return (nums2[n/2])*1.0;
        }
        int i = getMediumCut(nums1, nums2, 0, m, m, n);
        int j = (m+n+1)/2 - i;
        if ((m + n) % 2 == 0) {
            if (i == 0) {
                if (j == n)
                    return (nums2[j-1] + nums1[i])*1.0/2;
                return (nums2[j-1] + min(nums1[i], nums2[j])) * 1.0 / 2;
            }
            if (j == 0) {
                if (i == m)
                    return (nums1[i-1]+nums2[j])*1.0/2;
                return (nums1[i-1]+min(nums1[i], nums2[j]))* 1.0 / 2;
            }
            if (i == m)
                return (max(nums1[i-1], nums2[j-1]) + nums2[j])*1.0/2;
            if (j == n)
                return (max(nums1[i-1], nums2[j-1]) + nums1[i])*1.0/2;
            return (max(nums1[i-1], nums2[j-1])+min(nums1[i], nums2[j]))*1.0 / 2;
        }
        else {
            if (i == 0)
                return nums2[j-1];
            if (j == 0)
                return nums1[i-1];
            return (max(nums1[i-1], nums2[j-1]))*1.0;
        }
    }
    
    int getMediumCut(vector<int>& nums1, vector<int>& nums2, int imin, int imax, int m, int n) {
        int i = (imin+imax)/2, j = (m+n+1)/2-i;
        if (j > 0 && i < m && nums1[i] < nums2[j-1]) {
            return getMediumCut(nums1, nums2, imin+1, imax, m, n);
        }
        if (i > 0 && j < n && nums2[j] < nums1[i-1])
        {
            return getMediumCut(nums1, nums2, imin, imax-1, m, n);
        }
        return i;
    }
    
};