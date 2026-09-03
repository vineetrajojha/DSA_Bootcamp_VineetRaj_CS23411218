class Solution {
public:
    void generateSubsets(int index, vector<vector<int>>& ans, vector<int>& nums, vector<int>& list) {
        if (index == nums.size()) {
            if (find(ans.begin(), ans.end(), list) == ans.end()) {
                ans.push_back(list);
            }
            return;
        }
        list.push_back(nums[index]);
        generateSubsets(index + 1, ans, nums, list);
        list.pop_back();
        generateSubsets(index + 1, ans, nums, list);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());  
        vector<int> list;
        generateSubsets(0, ans, nums, list);
        return ans;
    }
};