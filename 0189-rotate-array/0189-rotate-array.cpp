class Solution {
public:
    void rotate(vector<int>& nu, int k) {
        int n=nu.size();
        k=k%n;
        vector<int>nu2(nu.begin(),nu.end());
        for(int i=0;i<n;i++){
            nu[i]=nu2[((i-k)+n)%n];
        }

    }
};