class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0, product=1, temp=n;
        while(n>0){
            int ld=n%10;
            sum+=ld;
            product*=ld;
            n/=10;
        } int ttl=sum+product;
        if(temp%ttl==0) return true; else return false;
        
    }
};