class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int a=-1;int b=-1;int c=-1;
        for(auto ele:triplets){
            if(ele[0]==target[0] && ele[1]<= target[1] && ele[2]<=target[2]){
                a=1;
            }
            if(ele[1]==target[1] && ele[0]<= target[0] && ele[2]<=target[2]){
                b =1;
            }
            if(ele[2]==target[2] && ele[0]<= target[0] && ele[1]<=target[1]){
                c=1;
            }
        }
        return (a==b && b==c) && a!=-1;
    }
};