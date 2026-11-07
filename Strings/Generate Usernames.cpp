class Solution {
  public:
    vector<string> generateUsernames(vector<string> arr) {
        // code here
        unordered_map<string,int>mpp;
                unordered_set<string>st;
                for(auto it : arr)st.insert(it);
                vector<string>ans;
                for(auto it : arr){
                    if(mpp.find(it) == mpp.end()){
                        ans.push_back(it);
                        mpp[it]++;
                        continue;
                    }
                    int cnt = mpp[it];
                    while(st.find(it + to_string(cnt)) != st.end()){
                        cnt++;
                    }
                    ans.push_back(it + to_string(cnt));
                    mpp[it] = cnt+1;
                }
                return ans;
    }
};
