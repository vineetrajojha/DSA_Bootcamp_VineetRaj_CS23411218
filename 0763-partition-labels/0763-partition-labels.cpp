class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26);
        for(int i=0;i<s.size();i++)
            last[s[i]-'a']=i;

        vector<int>sol;
        int end=-1,prev=-1;
         for(int i= 0; i <s.size();i++) {
            end=max(end,last[s[i]-'a']);
            if(end==i){
                sol.push_back(i-prev);
                prev=i;
            }
        }
        return sol;
        
    }
};