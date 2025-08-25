class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<int>ans;
        int i=0,j=0;
        while(i<n&&j<m){
            if(nums1[i]<=nums2[j]){ans.push_back(nums1[i]);i++;}
            else{ans.push_back(nums2[j++]);}
        }
        while(i<n)ans.push_back(nums1[i++]);
        while(j<m)ans.push_back(nums2[j++]);
        if((n+m)&1)return (double)ans[(n+m)/2];
        return (double)(ans[(n+m)/2]+ans[(n+m)/2-1])/2;
    }
};