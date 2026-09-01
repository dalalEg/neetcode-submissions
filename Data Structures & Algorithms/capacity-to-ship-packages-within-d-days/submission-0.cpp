class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int res =accumulate(weights.begin(), weights.end(), 0),mx=res;
        int mn=*max_element(weights.begin(),weights.end());
        while(mn <=mx){
            int curr_weight=(mn+mx)/2;
            int curr_days=1,prev_weight=0;
            for(int weight:weights){
                prev_weight+=weight;
                if(prev_weight>curr_weight){
                    curr_days++;
                    prev_weight=weight;
                }
            }
            if(curr_days<=days){
                mx=curr_weight-1;
                res=min(res,curr_weight);
            }else{
                mn=curr_weight+1;
            }
        }
        return res;
    }

};