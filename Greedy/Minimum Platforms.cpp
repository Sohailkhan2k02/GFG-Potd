//T.C : O(n)
//S.C : O(2600)
class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code her
        int n=arr.size();
        vector<int>gain(2600,0);
    	for(int i=0; i<n; i++){
    	    gain[arr[i]]++;
    	    gain[dep[i]+1]--;
    	}
    	
    	for(int i=1; i<2600; i++){
    	    gain[i]+=gain[i-1];
    	}
    	
    	return *max_element(gain.begin(),gain.end());
    }
};
