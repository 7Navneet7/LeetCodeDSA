class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ld=0,hd=arr.size()-1;
        while(ld<hd){
            int md=(ld+hd)/2;
            if(arr[md]<arr[md+1]){
                ld=md+1;
            }
            else hd=md;
        }
        return ld;
    }
};