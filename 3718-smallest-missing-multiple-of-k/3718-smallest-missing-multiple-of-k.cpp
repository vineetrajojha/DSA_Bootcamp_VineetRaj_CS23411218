class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> freq(nums.begin(), nums.end());

        int prod = k;

        while (true) {
            if (freq.count(prod) == 0) {
                return prod;
            }
            prod += k;
        }
    }
};