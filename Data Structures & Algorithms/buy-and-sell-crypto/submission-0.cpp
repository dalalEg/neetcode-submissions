class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res =0;
        int n = prices.size();
        int buy =prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]>buy){
                res=max(res,prices[i]-buy);
            }else{
                buy=prices[i];
            }
        }
        return res;
    }
};
