class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size=temperatures.size();
        vector<int> res(size,0);
        stack<int> ist;
        for(int index=0;index<size;index++){
            while(!ist.empty()&&temperatures[ist.top()]<temperatures[index]){
                res[ist.top()]=index -ist.top();
                ist.pop();

            }
            ist.push(index);
        }

        return res;
    }
};
