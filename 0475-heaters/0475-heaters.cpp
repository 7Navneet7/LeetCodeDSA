using lld=double;
const lld eps=1e-9;
class Solution {
public:
//     bool ok(int d, vector<int>& houses, vector<int>& heaters){
//     int i = 0, j = 0;

//     while(i < houses.size()){
//         if(j == heaters.size()) return false;

//         if(abs(houses[i] - heaters[j]) <= d){
//             i++;
//         } else {
//             j++;
//         }
//     }

//     return true;
// }

    bool ok(int d,vector<int>ho,vector<int>he){
        int i=0;int j=0;
        while(i<ho.size()){
            if(j==he.size())return false;
            if(abs(ho[i]-he[j])<=d)i++;
            else j++;
        }
        return true;
    }
    int findRadius(vector<int>& ho, vector<int>& he) {
        sort(he.begin(),he.end());sort(ho.begin(),ho.end());
        int ld=0,hd=1e9,ans=hd;
        while(ld<=hd){
            int md=(ld+hd)/2;
            if(ok(md,ho,he)){
                ans=md;
                hd=md-1;
            }
            else{
                ld=md+1;
            }
        }
        return ans;
    }    

//     int findRadius(vector<int>& houses, vector<int>& heaters) {
//     sort(houses.begin(), houses.end());
//     sort(heaters.begin(), heaters.end());

//     int l = 0, r = 1e9, ans = r;

//     while(l <= r){
//         int mid = (l + r) / 2;

//         if(ok(mid, houses, heaters)){
//             ans = mid;
//             r = mid - 1;
//         } else {
//             l = mid + 1;
//         }
//     }

//     return ans;
// }
};