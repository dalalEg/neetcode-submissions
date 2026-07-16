class Solution {
   public:
    int calPoints(vector<string>& operations) {
        vector<int> vc;
        int count = 0;
        for (string op : operations) {
            if (op == "+") {
                int val = vc[count - 1] + vc[count - 2];
                count++;
                vc.push_back(val);
            } else if (op == "D") {
                int val = vc[count - 1] * 2;
                count++;
                vc.push_back(val);

            } else if (op == "C") {
                vc.pop_back();
                count--;
            } else {
                count++;
                vc.push_back(stoi(op));
            }
        }
        return accumulate (vc.begin(), vc.end(),0);
    }
};