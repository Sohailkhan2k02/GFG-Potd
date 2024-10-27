//T.C : O(n*n)
//S.C : O(n)
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        // Your code
         unordered_set<int>st(arr.begin(), arr.end());
        int n=arr.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(st.find(arr[i]+arr[j])!=st.end()){
                    return 1;
                }
            }
        }
        return 0;
    }
};
