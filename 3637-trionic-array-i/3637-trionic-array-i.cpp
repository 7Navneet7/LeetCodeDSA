
// class Solution {
// public:
//     bool isTrionic(vector<int>& nums) {
//         bool f1=0,f2=0;bool f3=0;
//         int n=nums.size();
//         for(int i=0;i<n-1;i++){
//             if(nums[i]<nums[i+1]){
//                 f1=1;
//             }
//             else if(f2 && f1 &&(nums[i]<nums[i+1])){
//                 f3=1;
//             }
//             else if(nums[i]>nums[i+1])f2=1;

//         }
//         return (f1 & f2 & f3);
//     }
// };
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size(), i = 1;
        while (i < n && nums[i - 1] < nums[i]) {
            i++;
        }
        int p = i - 1;
        while (i < n && nums[i - 1] > nums[i]) {
            i++;
        }
        int q = i - 1;
        while (i < n && nums[i - 1] < nums[i]) {
            i++;
        }
        int flag = i - 1;
        return (p != 0) && (q != p) && (flag == n - 1 && flag != q);
    }
};