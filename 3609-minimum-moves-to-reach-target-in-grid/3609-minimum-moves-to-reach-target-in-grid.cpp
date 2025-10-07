class Solution {
public:
    int minMoves(int sx, int sy, int tx, int ty) {
        if(sx==0 && sy==0){
            return (tx==0 && ty==0)?0:-1;
        }
        int res=0;
        while(tx!=sx||ty!=sy){
            if(sx>tx||sy>ty)return -1;
            res++;
            if(tx>ty){
                if(tx>2*ty){
                    if(tx&1)return -1;
                    tx/=2;
                }
                else tx-=ty;
            }
            else if(ty>tx){
                if(ty>2*tx){
                    if(ty&1)return -1;
                    ty/=2;
                }
                else ty-=tx;
            }
            else{
                if(sx==0){
                    tx=0;
                }
                else if(sy==0)ty=0;
                else return -1;
            }
        }
        return res;
    }
};