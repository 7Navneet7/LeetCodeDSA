class Solution {
    public int binaryGap(int n) {
        String st=Integer.toBinaryString(n);
        int curr=10000;
        int mx=0;
        for(int i=0;i<st.length();i++){
            if(st.charAt(i)=='1'){
                mx=Math.max(mx,i-curr);
                curr=i;
            }
        }
        return mx;
    }
}