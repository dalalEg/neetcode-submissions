class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool x=false,y=false,z=false;
        for (const auto& t: triplets){
            x|=((target[0]==t[0]) && (t[1]<=target[1]) &&(t[2]<=target[2]));
            y|=((target[0]>=t[0]) && (t[1]==target[1]) &&(t[2]<=target[2]));
            z|=((target[0]>=t[0]) && (t[1]<=target[1]) &&(t[2]==target[2]));
            if (x &&y && z)
                return true;
        }
        return false;
    }
};
