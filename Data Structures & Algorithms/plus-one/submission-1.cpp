class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1 , n= digits.size();
        for( int i= n-1;i>=0;i--){
            int curr = digits[i]+carry;
            digits[i]=curr%10;
            carry=curr/10;
        } 
        if (carry !=0){
            digits.resize(n+1);
            rotate(digits.begin(),digits.begin() + 1, digits.end());
            digits[0]=1;
        }
        return digits;
    }
};
