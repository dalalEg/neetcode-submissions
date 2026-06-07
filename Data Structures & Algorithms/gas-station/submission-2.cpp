class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int g=0,res=0;
        int sum =0 ;
        for (int i=0;i<gas.size();i++){
            sum+=(gas[i]-cost[i]);
        }
        if (sum<0)
            return -1;
        for (int i=0;i<gas.size();i++){
            g+=(gas[i]-cost[i]);
            if (g <0){
                g=0;
                res=i+1;
            }
        }
                    return res;

    }
};
