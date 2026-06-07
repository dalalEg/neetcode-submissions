class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int r = piles[0], l = 1;
        for (int i = 1; i < n; i++) {
            r = max(r, piles[i]);
        }
        auto canEat = [&](int k) {
            int i = 0, j = 0;
            while (j < h&&i<n) {
                j += piles[i] / k;
                j = piles[i] % k == 0 ? j:j+1;
                j + 1;
                i++;
                if(i==n&&j<=h)
                  return true;
            }
            return false;
        };
        int res = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canEat(mid)) {
                res = mid;   // Store the lowest valid max value
                r = mid - 1; // Try to minimize it further
            } else {
                l = mid + 1; // Increase `w`
            }
        }
        return res;
    }
};
