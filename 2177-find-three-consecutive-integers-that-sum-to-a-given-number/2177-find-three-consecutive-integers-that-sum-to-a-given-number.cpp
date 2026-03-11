using ll=long long;
class Solution {
public:
    vector<long long> sumOfThree(long long nums) {
        if(nums%3!=0)return {};
        else{
            return{nums/3-1,nums/3,nums/3+1};
        }
    }
};