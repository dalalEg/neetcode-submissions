class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        unordered_map<char,int> index;
        int n= s.size() , maxIndex=-1,start=0;
        for (int i=0;i<n;i++){
            index[s[i]]=i;
        }
        for (int i=0;i<n;i++){
            maxIndex=max(maxIndex,index[s[i]]);
            if(i==maxIndex){
                res.push_back((maxIndex-start+1));
                start=i+1;
                maxIndex=i<n-1 ? index[s[i+1]]:-1;
            }
        }  
        return res;
    }
};
