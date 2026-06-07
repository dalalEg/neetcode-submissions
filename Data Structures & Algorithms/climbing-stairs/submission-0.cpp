class Solution {
    int dp(int i,int n){
        if(i==n) return 1;
        if(i>n) return 0;
        return dp(i+1,n)+dp(i+2,n);
    }
public:
    int climbStairs(int n) {
        return dp(0,n);
    }
};
