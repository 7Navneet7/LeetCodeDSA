class Solution {
    public int minFlips(int a, int b, int c) {
        String cs=Integer.toBinaryString(c);
        String as=Integer.toBinaryString(a);
        String bs=Integer.toBinaryString(b);
        int n=Math.max(cs.length(),Math.max(as.length(),bs.length()));
        as=String.format("%"+n+"s",as).replace(' ','0');
        bs=String.format("%"+n+"s",bs).replace(' ','0');
        cs=String.format("%"+n+"s",cs).replace(' ','0');
        int ops=0;
        for(int i=0;i<n;i++){
            if(cs.charAt(i)=='0'){
                if(as.charAt(i)=='1')ops++;
                if(bs.charAt(i)=='1')ops++;
            }
            else{
                if(as.charAt(i)=='0' && bs.charAt(i)=='0')ops++;
            }
        }
        return ops;

    }
}