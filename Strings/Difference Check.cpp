class Solution {
  public:
    int minDifference(vector<string> &arr) {
        // code here
        int n = arr.size();
        
        vector<int> seconds;
        
        for(auto& timee : arr){
            int hourInSeconds = stoi(timee.substr(0, 2)) * 3600;
            int minuteInSeconds = stoi(timee.substr(3, 2)) * 60;
            int second = stoi(timee.substr(6, 2));
            
            seconds.push_back(hourInSeconds + minuteInSeconds + second);
        }
        
        sort(begin(seconds), end(seconds));
        
        
        int res = min(seconds[n - 1] - seconds[0], 86400 - (seconds[n - 1] - seconds[0]));
        
        for(int i = 1; i < n; ++i){
            res = min(res, seconds[i] - seconds[i - 1]);
        }
        
        return res;
    }
};
