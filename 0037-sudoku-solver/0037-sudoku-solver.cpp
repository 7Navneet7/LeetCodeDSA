class Solution {
public:
    bool valid(int r,int c,char ch,vector<vector<char>>&brd){
        for(int i=0;i<9;i++){
            //col check
            if(brd[i][c]==ch)return 0;
            //row check
            if(brd[r][i]==ch)return 0;
            // check 3x3 sub box constraint
            int bxr=3*(r/3)+i/3;
            int bxc=3*(c/3)+i%3;
            if(brd[bxr][bxc]==ch)return 0;  
        }
        return 1;
    }
    bool solve(vector<vector<char>>& brd){
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(brd[r][c]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(valid(r,c,ch,brd)){
                            brd[r][c]=ch;
                            // recurse to fill the rest
                            if(solve(brd))return 1;
                            brd[r][c]='.';
                        }
                    }
                    //no digit from 1 to 9 works here so
                    return 0;
                }
            }
        }
        return 1;
    }
    void solveSudoku(vector<vector<char>>& brd) {
        solve(brd);
    }
};