class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        // int n,m, size()
        int n = word1.size();
        int m = word2.size();

        //pointers
        vector<int> right(n);
        int cnter=0;
        int R = m-1;

        //for loop
        for ( int i = n-1;i>=0;i--){
            right[i]=cnter;
            if(R>=0 && word2[R]==word1[i]){
                R--;
                cnter++;
            }
        }

        //bool
        vector<int>ans;
        bool change = false;
        int j =0;

        //for loop 
        for( int i =0;i<n && j <m;i++){
            if(word1[i] == word2[j]){
                ans.push_back(i);
                j++;
            }
            else if ( !change && right[i]>=m-j-1){
                ans.push_back(i);
                j++;
                change=true;
            }
        }

        //base case
        if (j==m){
            return ans;
        }
        return {};
        
    }
};