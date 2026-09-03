class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int left=0,ldup=0; int in; int count=0,c=0;
        for(in=0;left+in<n and nums[left+in]==0;in++){
            continue;
        } int r;
        for(r=0;r<n;r++){
            if(nums[r]==1){
                c++;
            } if(c>goal){
                left=left+in+1;
                for(in=0;left+in<=n and nums[left+in]==0;in++){
                    continue;
                }c--;
            }
            if(c==goal){
                count=count+min(in,r-left)+1;
            }
        }
        return count;
        
    }
};