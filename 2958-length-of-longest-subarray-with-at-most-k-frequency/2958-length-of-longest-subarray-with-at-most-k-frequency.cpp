class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0, ans = 0;
        unordered_map<int, int> freq;

        for(int r = 0; r < nums.size(); r++) {
            freq[nums[r]]++; // add right element

            while(freq[nums[r]] > k) { // until window invalid
                freq[nums[l]]--;  // remove left element
                l++;  // shrink from left
            }

            ans = max(ans, r - l + 1); // update max length
        }

        return ans;
    }
};