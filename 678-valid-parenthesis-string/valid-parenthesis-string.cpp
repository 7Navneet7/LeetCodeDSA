class Solution {
public:
    // bool checkValidString(string s) {
    //     int l=0,r=0,st=0;bool f=0;
    //     for(int i=0;i<s.length();i++){
    //         if(s[i]=='('){
    //             l++;f=!f;
    //         }
    //         else if(s[i]==')'){
    //             r++;f=!f;
    //         }
    //         else{
                
    //             st++;
    //         }
    //     }
    //     if((!f && l==r||abs(l-r)==st))return true;
    //     return false;
        
    // }





    bool checkValidString(string s){
        int leftMin=0,leftMax=0;
        for(char c:s){
            if(c=='('){
                leftMin++;leftMax++;
            }
            else if(c==')'){
                leftMin--;leftMax--;
            }
            else{
                leftMin--;leftMax++;
            }
            if(leftMax<0)return false;
            if(leftMin<0){
                leftMin=0;
                leftMax-=(-1*leftMin);
                if(leftMax<0)return false;
            }    
        }
        return leftMin==0;
    }
};