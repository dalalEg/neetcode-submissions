class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n+1,0);
        
        for(int i=1;i<=n;i++){
            if(i==1 || i==2){
                dp[i]=1;
                continue;
            }
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
};