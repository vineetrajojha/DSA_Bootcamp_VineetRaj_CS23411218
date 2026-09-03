class Solution {
public:
    bool canJump(vector<int>& nums) {
        //n=size and max=0
        int n = nums.size();
        int maxReach = 0;

        //for and i>max then false
        for (int i =0;i<n;i++){
            if(i>maxReach) return false;
            maxReach = max(maxReach,i+nums[i]);
        }
        return true;


        
    }
};