class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();sort(people.begin(),people.end());
        int i=0,j=n-1;int cnt=0;
        while(i<=j){
            if(people[i]+people[j]>limit){
                cnt++;j--;
            }
            if(i>j)break;
            if(people[i]+people[j]<=limit){
                cnt+=1;i++;j--;
            }


        }
        return cnt;
    }
};