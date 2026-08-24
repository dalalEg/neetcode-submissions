class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n =piles.size();
        int r=*max_element(piles.begin(),piles.end());
        int l=1;
        int ans=r;
        while (l<=r){
            int mid=l+(r-l)/2;
            int curr=0;
            for (auto pile : piles){
                curr+=pile/mid;
                   curr= (pile%mid==0) ? curr: curr+1;
            }
            if(curr<=h){
                ans=min(ans,mid);
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;

    }
};
