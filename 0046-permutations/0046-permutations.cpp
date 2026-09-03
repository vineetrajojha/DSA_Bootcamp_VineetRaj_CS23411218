class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        solve(res,nums,0);
        return res;
        
    }
    void solve(vector<vector<int>> & res, vector<int>& nums, int index){
        if(index==nums.size()){
            res.push_back(nums);
        }
        for(int i= index;i<nums.size(); i++){
            swap(nums[index], nums[i]);
            solve(res, nums, index+1);
            swap(nums[i], nums[index]);
        }
        return;
    }
};