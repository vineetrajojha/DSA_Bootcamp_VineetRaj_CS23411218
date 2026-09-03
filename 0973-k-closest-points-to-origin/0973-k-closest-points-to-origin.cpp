class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if(k>=points.size()){
            return points;
        }
        vector<double>distance(points.size(),0);
        for(int i=0;i<points.size(); i++){
             distance[i] = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
        } vector<double> sortedDistance=distance;
        sort(sortedDistance.begin(), sortedDistance.end());
        double kthDistance=sortedDistance[k-1];
        vector<vector<int>>ans;
        for(int i=0;i<points.size();i++){
            if(distance[i]<=kthDistance){
                ans.push_back(points[i]);
            }
        }
        return ans;
        
    }
};