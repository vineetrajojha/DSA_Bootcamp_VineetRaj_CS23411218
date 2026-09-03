class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans;

        int v=0;
        if(m*n != original.size()){
            return {};
        }
        vector<int>res;
        for(int i=0;i<original.size();i++){
            res.push_back(original[i]);
            v++;
            if(v==n){
                ans.push_back(res);
                res.clear();
                v=0;
            }

        }
        return ans;
        
    }
};