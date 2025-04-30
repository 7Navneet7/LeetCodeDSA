class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>que;
        for(int x:nums)que.push(x);
        while(k>1){
            que.pop();
            k--;
        }
        return que.top();
    }
};