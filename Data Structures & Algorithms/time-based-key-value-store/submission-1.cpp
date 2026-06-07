class TimeMap {
    unordered_map<string,vector<pair<int,string>>> mpp;
public:

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        int l=0,h=mpp[key].size()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(mpp[key][mid].first==timestamp) return mpp[key][mid].second;
            else if(mpp[key][mid].first>timestamp) h=mid-1;
            else l=mid+1;
        }
        if(h<0) return "";
        return mpp[key][h].second;
    }
};
