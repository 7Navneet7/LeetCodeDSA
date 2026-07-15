class Solution {
public:
    int findKthLargest(vector<int>& nu, int k) {
        priority_queue<int,vector<int>>pq;
        for(auto &it:nu){
            pq.push(it);
        }
        while(k>1){
            pq.pop();k--;
        }
        return pq.top();
    }
};