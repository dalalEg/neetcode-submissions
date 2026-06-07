class Solution {
public:
void generateAll(string st,int openP,int closeP,int n , vector<string>& res){
    if(closeP>openP || openP>n/2)
     return;
     if(closeP==openP&&st.size()==n){

     cout<<st;
        res.push_back(st);
     }
    generateAll(st+")",openP,closeP+1,n,res);
     
    generateAll(st+"(",openP+1,closeP,n,res);

}
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string start="(";
        generateAll(start,1,0,n*2,res);
        return res;
    }
};
