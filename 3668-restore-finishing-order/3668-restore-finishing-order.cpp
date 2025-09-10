class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        set<int>fst(friends.begin(),friends.end());vector<int>ans;
        for(int x:order){
            if(fst.count(x))ans.push_back(x);
        }
        return ans;
    }
};