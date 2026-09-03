class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>visited(n,0);
        queue<int>q;
        q.push(source);
        visited[source]=1;

        while(!(q.empty())){
            int temp = q.front();
            q.pop();
            if(temp==destination)return true;
            for(int padosi : adj[temp]){
                if(visited[padosi]==0){
                    visited[padosi]=1;
                    q.push(padosi);
                }
            }
        }
        return false;
    }
};