//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        stack<pair<int,int>>st;
        vector<int>ans;
        ans.push_back(1);
        st.push({arr[0],1});
        int count=0;
        bool flag;
        for(int i=1;i<arr.size();i++){
            count=1;
            flag=false;
            while(!st.empty()){
                int topfirst=st.top().first;
                int topsecond=st.top().second;
                if(topfirst>arr[i]){
                    st.push({arr[i],count});
                    ans.push_back(count);
                    break;
                }else{
                    st.pop();
                    count=count+topsecond;
                    flag=true;
                    
                }
            }
            
            if(flag=true&&st.size()==0){
            st.push({arr[i],count});
            ans.push_back(count);
            }
            
        }
        return ans;
    }
};
