class TimeMap {
    unordered_map<string, vector<pair<int, string>>> timeMap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {

        vector<pair<int,string>>& timeArray = timeMap[key];

        int l = 0;
        int r = timeArray.size() - 1;
        int mid = 0;
        int maxPrev = -1;
        while(l <= r) {
            mid = l + (r - l) / 2;

            if(timeArray[mid].first == timestamp) return timeArray[mid].second;
            else if(timeArray[mid].first > timestamp) r = mid - 1;
            else {
                maxPrev = max(maxPrev, mid);
                l = mid + 1;
            }
        }

        return maxPrev >= 0 ? timeArray[maxPrev].second : "";
    }
};
