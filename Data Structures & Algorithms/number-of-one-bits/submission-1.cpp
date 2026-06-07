class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        for (int i=0;i<32;i++){
            int curr=(n>>i)&1;
            count= curr==1?count+1:count;
        }
        return count;
    }
};
