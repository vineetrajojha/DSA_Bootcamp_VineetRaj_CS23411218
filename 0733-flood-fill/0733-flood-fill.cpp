class Solution {
public:
    bool isValid(int x,int y,int rows,int cols){
        return (x>=0 && x<rows && y>=0 && y<cols);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>res=image;
        vector<int>dx={0,1,0,-1},dy={-1,0,1,0};
        int rows=image.size(),cols=image[0].size();
        vector<vector<bool>>vis(rows,vector<bool>(cols,false));
        stack<pair<int,int>>st;
        st.push({sr,sc});
        res[sr][sc]=color;
        while(!st.empty()){
            pair<int,int>p=st.top();
            st.pop();
            int x=p.first,y=p.second;
            vis[x][y]=true;
            for(int i=0;i<4;i++){
                int ax=x+dx[i];
                int ay=y+dy[i];
                if(isValid(ax,ay,rows,cols)&&!vis[ax][ay]&&image[x][y]==image[ax][ay]){
                    st.push({ax,ay});
                    res[ax][ay]=color;
                }
            }
        }
        return res;
    }
};