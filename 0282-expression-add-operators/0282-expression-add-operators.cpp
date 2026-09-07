class Solution {
    using ll=long long;
public:
    void bt(int idx,string path,ll eval,ll pvop,string &num,int tar,vector<string>&ans){
        if(idx==num.size()){
            if(eval==tar){
                ans.push_back(path);
            }
            return;
        }
        for(int i=idx;i<num.size();i++){
            if(i>idx && num[idx]=='0'){
                break;
            }
        
        string part=num.substr(idx,i-idx+1);
        ll val=stoll(part);
        if(idx==0){
            bt(i+1,part,val,val,num,tar,ans);
        }
        else{
            bt(i+1,path+"+"+part,eval+val,val,num,tar,ans);
            bt(i+1,path+"-"+part,eval-val,-val,num,tar,ans);
            bt(i+1,path+"*"+part,eval-pvop+(pvop*val),pvop*val,num,tar,ans);
        }
        }
    }
    vector<string> addOperators(string num, int tar) {
        vector<string>ans;
        if(num.empty())return ans;
        bt(0,"",0,0,num,tar,ans);
        return ans;
    }
};