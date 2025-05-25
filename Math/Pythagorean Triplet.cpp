//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        int n=arr.size();
        unordered_set<int>st;
	    for(int i=0; i<n; i++){
	        st.insert(arr[i]*arr[i]);
	    }
	    for(int i=0; i<n; i++){
	        int ptr=arr[i]*arr[i];
	        for(int j=i+1; j<n; j++){
	            int qtr=arr[j]*arr[j];
	            int rtr=ptr+qtr;
	            
	            if(st.find(rtr)!=st.end())
	            return true;
	        }
	    }
	    return false;
    }
};
