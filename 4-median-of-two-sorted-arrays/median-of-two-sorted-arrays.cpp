class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();int n=n1+n2;
        int i=0,j=0,cnt=0,indl1=-1,indl2=-1;
        int ind1=n/2-1,ind2=n/2;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                if(cnt==ind1)indl1=nums1[i];
                if(cnt==ind2)indl2=nums1[i];
                cnt++;i++;
            }
            else{
                if(cnt==ind1)indl1=nums2[j];
                if(cnt==ind2)indl2=nums2[j];
                cnt++;j++;
            }
        }
        while(i<n1){
            
                if(cnt==ind1)indl1=nums1[i];
                if(cnt==ind2)indl2=nums1[i];
                cnt++;i++;
            
        }
        while(j<n2){
            
                if(cnt==ind2)indl2=nums2[j];
                if(cnt==ind1)indl1=nums2[j];
                cnt++;j++;
            
        }
        if(n &1){return (double)indl2;}
        return (double)((double)(indl1+indl2))/2.0;
    }
};