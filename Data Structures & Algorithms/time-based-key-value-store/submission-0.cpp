class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if(mpp.find(key)==mpp.end()){
            mpp[key]={{timestamp,value}};
        }
        else{
            mpp[key].push_back({timestamp,value});
        }
    }
    
    string get(string key, int timestamp) {
        if(mpp.find(key)==mpp.end()) return "";
        
        int low=0;
        int high=mpp[key].size()-1;

        if(timestamp<mpp[key][low].first) return "";
        if(timestamp>mpp[key][high].first) return mpp[key][high].second;
        
        int ansIndex=high;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(mpp[key][mid].first<=timestamp){
                ansIndex=mid;
                low=mid+1;
            }
            else high=mid-1;
        }

        return mpp[key][ansIndex].second;
    }
};