// class Solution {
// public:
//     int threeSumClosest(vector<int>& nums, int target) {
//         sort(nums.begin(),nums.end());
//         int d;
//         for(int i=0;i<nums.size();i++){
//             int j=i+1;
//             int di;
//             int k=nums.size()-1;
//             int sum=nums[i]+nums[j]+nums[k];
//             if(sum==target){
//                 d=0;
//                 break;
//             }
//             else if(sum<target){
//                 di=target-sum;
//                 j++;
//             }
//             else{
//                 di=sum-target;
//                 k--;
//             }
//             if(di<d){
//                 d=di;
//             }
//         }
//         return d;
//     }
// }
class Solution{
    public:
    int threeSumClosest(std::vector<int>& nums,int target){
        int clos_sum=std::numeric_limits<int>::max();
        int clos_diff=std::numeric_limits<int>::max();
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    int c_s=nums[i]+nums[j]+nums[k];
                    int c_d=std::abs(c_s-target);
                    if(c_d<clos_diff){
                        clos_diff=c_d;
                        clos_sum=c_s;
                    }
                }
            }
        }
        return clos_sum;
    }
};