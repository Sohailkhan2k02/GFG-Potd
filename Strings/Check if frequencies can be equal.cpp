// T.C: O(n) 
// S.C: O(n)

class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    unordered_map<char,int>mpp;
	    for(auto i:s){
	        mpp[i]++;
	    }
	    int val=mpp[s[0]];
	    int cnt=0;
	    for(auto i:mpp){
	        if(i.second!=val){
	            int diff=abs(val-i.second);
	            if(diff>1){
	                return 0;
	            }
	            cnt++;
	        }
	        if(cnt>1){
	            return 0;
	        }
	    }
	    return 1;
	}
};
