//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        unordered_map<int,int>freq;
        
        for(auto x:arr){
            freq[x]++;
        }
        vector<pair<int,int>>newArr;
        for(auto x:arr){
            newArr.push_back({x,freq[x]});
        }
        
        // Next Greater Element
        stack<pair<int,int>>st;
        int n=newArr.size();
        st.push({INT_MAX,INT_MAX});
        vector<int>res(n);
        for(int i=n-1;i>=0;i--){
            while(st.top().second<=newArr[i].second){
                st.pop();
            }
            if(st.top().first!=INT_MAX) res[i]=st.top().first;
            else res[i]=-1;
            st.push({newArr[i].first,newArr[i].second});
            
        }
        
        
        return res;
    }
};
