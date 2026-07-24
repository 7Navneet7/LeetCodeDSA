class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int col) {
        int oc=img[sr][sc];
        if(oc==col)return img;
        queue<pair<int,int>>q;q.push({sr,sc});
        int rs=img.size();int cs=img[0].size();
        img[sr][sc]=col;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto cc=q.front();q.pop();
                int x=cc.first;int y=cc.second;
                if(x-1>=0 && img[x-1][y]==oc){
                    img[x-1][y]=col;
                    q.push({x-1,y});
                }
                if(y-1>=0 && img[x][y-1]==oc){
                    img[x][y-1]=col;
                    q.push({x,y-1});
                }
                if(x+1<rs && img[x+1][y]==oc){
                    img[x+1][y]=col;
                    q.push({x+1,y});
                }
                if(y+1<cs && img[x][y+1]==oc){
                    img[x][y+1]=col;
                    q.push({x,y+1});
                }
            }
        }
        return img;
        
    }
};