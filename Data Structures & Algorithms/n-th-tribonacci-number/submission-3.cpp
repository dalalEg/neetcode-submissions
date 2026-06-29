class Solution {
public:
    int tribonacci(int n) {
        if (n <= 2) {
            return n == 0 ? 0 : 1;
        }
        int v0=0,v1=1,v2=1;
        for(int i=3;i<=n;i++){
            int temp=v0+v1+v2;
            v0=v1;
            v1=v2;
            v2=temp;
        }
        return v2;
    }
};