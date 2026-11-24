class TimeMap {
    unordered_map<string, vector<pair<int, string>>> keyStore;  // keyStore[key]={timestamp,val}

   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        keyStore[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        int n = keyStore[key].size();
        int l = 0, r = n - 1;
        string c="";
        while (l <= r) {
            int mid =(l+r)/ 2;
            if (keyStore[key][mid].first <= timestamp) {
                l = mid + 1;
                c= keyStore[key][mid].second;
            } else {
                r = mid-1 ;
            }
        }
        return c ;
    }
};
