//T.C : O(n)
//S.C : O(n)
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        unordered_set<int>st;
          int len=0;
          for(int i=0; i<n; i++){
              st.insert(arr[i]);
          }
          
          for(int i=0; i<n; i++){
              if(st.find(arr[i]-1)!=st.end()){
                  continue;
              }
              else{
                  int j=arr[i];
                  while(st.find(j)!=st.end())
                      j++;
                      len=max(len,j-arr[i]);
              }
          }
          return len;
    }
};
