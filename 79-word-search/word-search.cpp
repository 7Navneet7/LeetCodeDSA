class Solution {
public:
    // bool exist(vector<vector<char>>& board, string word) {
    //     int n=board.size(); int m=board[0].size();
    //     function<bool (int,int,int)> search=[&](int i,int j,int k){
    //         if(k==word.length())return true;
    //         if(i<0||i>=n||j<0||j>=m||board[i][j]!=word[k])return false;

    //         char temp=board[i][j];
    //         board[i][j]='\0';
    //         if(search(i-1,j,k+1) || search(i+1,j,k+1) || search(i,j-1,k+1) ||   search(i,j+1,k+1)){
    //             return true;
    //         }
    //         board[i][j]=temp;
    //         return false;
    //     };

    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(search(i,j,0))return true;
    //         }
            
    //     }
    //     return false;
    // }


    bool searchNext(vector<vector<char>>&board,string word,int r,int c,int ind){
        if(ind==word.size())return true;
        int n=board.size(),m=board[0].size();
        if(r<0||c<0||r==n||c==m||board[r][c]!=word[ind]||board[r][c]=='!')return false;
        char ch=board[r][c];
        board[r][c]='!';
        
        bool top=searchNext(board,word,r-1,c,ind+1);
        bool right=searchNext(board,word,r,c+1,ind+1);
        bool bottom=searchNext(board,word,r+1,c,ind+1);
        bool left=searchNext(board,word,r,c-1,ind+1);

        board[r][c]=ch;
        return top||right||bottom||left;
    }

    bool exist(vector<vector<char>>&board,string word){
        int n=board.size(),m=board[0].size();
        int ind=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[ind]){
                    if(searchNext(board,word,i,j,ind)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};