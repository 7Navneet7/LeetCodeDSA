class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size(),cols=matrix[0].size();
        vector<int>rowset,colset;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    rowset.push_back(i);colset.push_back(j);
                }
            }
        }
        for(int r=0;r<rowset.size();r++){
            for(int j=0;j<cols;j++){
                matrix[rowset[r]][j]=0;
            }
        }
        for(int c=0;c<colset.size();c++){
            for(int i=0;i<rows;i++){
                matrix[i][colset[c]]=0;
            }
        }
        
    }
};