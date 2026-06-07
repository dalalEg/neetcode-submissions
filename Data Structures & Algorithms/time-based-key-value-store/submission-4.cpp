class TimeMap {
    map<string, vector<string>> mp;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        if (mp.find(key) != mp.end()) {
            mp[key][timestamp] = value;
        } else {
            vector<string> vec(1001, "");
            vec[timestamp] = value;
            mp[key] = vec;
        }
    }

    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) {
            return "";
        }
        vector<string> vec = mp[key];
        if (timestamp<=1000&&vec[timestamp] != "")
            return vec[timestamp];
            
         int r=min(1000,timestamp);
         while(vec[r] == "" && r>=0)
          r--;
        return r>=0 ?vec[r] : "";
    }
};
