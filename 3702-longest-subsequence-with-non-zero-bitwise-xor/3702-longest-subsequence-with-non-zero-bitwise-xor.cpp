class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int n = nums.size();
        bool isAllzero = true;
        int xorr=0;

        for(int i=0;i<n;i++){
            xorr^=nums[i];

            if(nums[i]!=0){
                isAllzero=false;
            }
        }
            if(xorr!=0){
                return n;
            }
            if(isAllzero) return 0;
        return n-1;
        
    }
};