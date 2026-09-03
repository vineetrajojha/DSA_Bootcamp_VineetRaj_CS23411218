class Solution {
public:
    long long dp[501][501];
    int MOD = 1e9 + 7;
    long long func(int p, int d){
        if(p==0 && d==0) return 1;
        if(dp[p][d]!=-1) return dp[p][d];
        long long res=0;
        if(p>0) res = (p*func(p-1,d+1))% MOD;
        if(d>0) res=(res+d*func(p,d-1))%MOD;
        return dp[p][d]=res;
    }
    int countOrders(int n) {
        memset(dp,-1,sizeof(dp));
        return func(n,0);
        
    }
};