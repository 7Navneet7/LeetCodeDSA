class Solution {
    public int minimumDistance(int[] nums) {
        int n=nums.length;
        Map<Integer,List<Integer>>pos=new HashMap<>();
        for(int i=0;i<n;i++){
            pos.putIfAbsent(nums[i],new ArrayList<>());
            pos.get(nums[i]).add(i);
        }
        int mn=Integer.MAX_VALUE;
        for(List<Integer>idx:pos.values()){
            if(idx.size()<3)continue;

            for(int i=0;i<=idx.size()-3;i++){
                int dif=idx.get(i+2)-idx.get(i);
                mn=Math.min(mn,dif);
            }
        }
        if(mn==Integer.MAX_VALUE)return -1;
        else return 2*mn;
    }
}