//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        unordered_map<char,int>mpp;
        for(char &c:s){
            mpp[c]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto i:mpp){
            pq.push({i.second, i.first});
        }
        
        while(!pq.empty() && k--){
            int freq=pq.top().first;
            char no=pq.top().second;
            freq--;
            mpp[no]--;
            pq.pop();
            pq.push({freq,no});
        }
        int cnt=0;
        for(auto i:mpp){
            cnt+=i.second*i.second;
        }
        return cnt;
    }
};
