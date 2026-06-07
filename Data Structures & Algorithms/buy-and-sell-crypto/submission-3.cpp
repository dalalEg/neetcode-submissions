class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int mx=0,mn= prices[0];
        for(int price:prices){
            res=max(res, price-mn);
            mn=min(price,mn);
        }
        return res;
    }
};
