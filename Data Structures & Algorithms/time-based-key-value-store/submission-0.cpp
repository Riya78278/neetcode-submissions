class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto &value=mp[key];
        int left=0;
        int right=value.size()-1;

        string res="";
        while(left <= right){
            int mid=left+(right-left)/2;
            if(value[mid].first<= timestamp){
                res=value[mid].second;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
