class Solution {
public:
    int m  ,n ;
    int dir[4][2] = {{1 ,0 } , {-1 , 0} , {0 , 1} , {0 , -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size() , n = grid[0].size();
        int res = 0;
        queue<pair<pair<int,int>, int>> q;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 2){
                    q.push({{i , j} , 0});
                } 
            }
        }


        while(!q.empty()){
            int r = q.front().first.first , c = q.front().first.second , x = q.front().second;
            q.pop();
            res = max(res , x);
            for(int i = 0 ; i < 4 ; i++){
               int nr = r + dir[i][0] , nc = c + dir[i][1];
               if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    if(grid[nr][nc] == 1){
                        q.push({{nr,nc} , x + 1});
                        grid[nr][nc] = 2;
                    }
               } 
            }
        }
        
        for(int i = 0 ; i < m ;  i++){
            for(int j = 0 ; j < n  ; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return res;
    }
};