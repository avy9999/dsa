class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0;
        int j = 0;
        int ind2 = (n1 + n2) >> 1;
        int ind1 = ind2 - 1;
        int cnt = 0;
        int el1 = 0, el2 = 0;
        while(i < n1 && j < n2){
            if (nums1[i] < nums2[j]){
                if (ind1 == cnt) el1 = nums1[i];
                if (ind2 == cnt) el2 = nums1[i];
                cnt++;
                i++;
            } else{
                if (ind1 == cnt) el1 = nums2[j];
                if (ind2 == cnt) el2 = nums2[j];
                cnt++;
                j++;
            }
        }
        while (i < n1){
            if (ind1 == cnt) el1 = nums1[i];
            if (ind2 == cnt) el2 = nums1[i];
            cnt++;
            i++;
        }
        while (j < n2){
            if (ind1 == cnt) el1 = nums2[j];
            if (ind2 == cnt) el2 = nums2[j];
            cnt++;
            j++;
        }
        if ((n1 + n2) % 2 == 1){
            return el2;
        }
        return (double) (el1 + el2) / 2.0;
    }
};