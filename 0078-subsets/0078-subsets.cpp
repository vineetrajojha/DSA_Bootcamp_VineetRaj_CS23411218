class Solution {
public:
void solve(vector<int> nums , vector<int> output , int i ,   vector<vector<int>> & result){
    if(i>=nums.size()){
    result.push_back(output);
    return;
    }


    // exclude
    solve(nums,output,i+1,result);

    // include
    int t = nums[i];
    output.push_back(t);

    solve(nums,output,i+1,result);


}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>output ;
        int i=0 ;
        vector<vector<int>> result;
        solve(nums,output,0,result);
        return result;
    }
};