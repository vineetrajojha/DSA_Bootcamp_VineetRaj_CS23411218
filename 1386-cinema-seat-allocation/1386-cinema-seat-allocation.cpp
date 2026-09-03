#define ll long long
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<bool>> grid;
        for(auto r:reservedSeats){
            int row=r[0],col=r[1];
            if(!grid.count(row)) grid[row]=vector<bool>(11, false);
            grid[row][col]=true;
        }
        ll ans=2LL*n;
        for(auto [num,row]:grid){
            bool left=!row[2] && !row[3] && !row[4] && !row[5];
            bool right=!row[6] && !row[7] && !row[8] && !row[9];
            bool middle=!row[4] && !row[5] && !row[6] && !row[7];
            int groups=0;
            if(left && right) groups=2;
            else if(left || middle || right) groups=1;
    
            ans-=2;
            ans+=groups;
        }
        return ans;
    }
};