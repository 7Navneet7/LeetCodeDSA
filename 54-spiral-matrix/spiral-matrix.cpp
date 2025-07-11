class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int>ans;
        int left=0,right=m-1,top=0,bottom=n-1;
        while(left<=right && top<=bottom){
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int j=top;j<=bottom;j++){
                ans.push_back(matrix[j][right]);
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right){
                for(int j=bottom;j>=top;j--){
                    ans.push_back(matrix[j][left]);
                }
                left++;
            }
        }
        return ans;
    }
};