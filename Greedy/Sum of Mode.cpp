class Solution {
  public:
    struct cmp{
        bool operator()(const pair<int, int> &a, const pair<int, int> &b)const {
            if(a.first == b.first){
                return a.second < b.second;
            }
            return a.first>b.first;
        }
    };
    
    int sumOfModes(vector<int>& arr, int k) {
        // code here
        set<pair<int, int>, cmp> st; //freq value
        unordered_map<int, int> mp; //value freq
        
        int res = 0;
        for(int i = 0; i< arr.size(); i++){
            if(i<k-1){
                int freq = mp[arr[i]];
                if(st.find({freq, arr[i]}) != st.end()){
                    st.erase({freq, arr[i]});
                }
                freq++;
                st.insert({freq, arr[i]});
                mp[arr[i]] = freq;
            }
            else{
                if(i == k - 1){
                    int freq = mp[arr[i]];
                    if(st.find({freq, arr[i]}) != st.end()){
                        st.erase({freq, arr[i]});
                    }
                    freq++;
                    if(freq){
                        st.insert({freq, arr[i]});
                    }
                    mp[arr[i]] = freq;
                }
                if(i-k >= 0 && arr[i] != arr[i-k]){
                    int freq = mp[arr[i-k]];
                    if(st.find({freq, arr[i-k]}) != st.end()){
                        st.erase({freq, arr[i-k]});
                    }
                    freq--;
                    if(freq){
                        st.insert({freq, arr[i-k]});
                    }
                    mp[arr[i-k]] = freq;
                    
                    freq = mp[arr[i]];
                    if(st.find({freq, arr[i]}) != st.end()){
                        st.erase({freq, arr[i]});
                    }
                    freq++;
                    if(freq){
                        st.insert({freq, arr[i]});
                    }
                    mp[arr[i]] = freq;
                }
                
                auto it = st.begin();
                // cout<<it->second<<" ";
                res += (it->second);
            }
        }
        return res;
    }
};
