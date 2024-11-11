//T.C : O(n*logn)
//S.C : O(n)
class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        // Code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        set<int>st;
        int val=0,mxx=0;
        for(int i=0; i<n; i++){
            mxx=max(arr[i],mxx);
            if(st.find(arr[i])!=st.end()){
                val+=mxx+1-arr[i];
                mxx++;
                st.insert(mxx);
            }
            else{
                st.insert(arr[i]);
            }
        }
        return val;
    }
};
