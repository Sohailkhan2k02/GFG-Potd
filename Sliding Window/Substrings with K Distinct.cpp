//T.C : O(n)
//S.C : O(1)
class Solution
{
  public:
    long long int f(string s,int k){
        int n=s.size();
    	vector<int>mpp(26,0);
    	long long int i=0,j=0;
    	long long int cnt=0;
    	long long int dis=0;
    	while(j<n){
    	    if(mpp[s[j]-'a']==0) dis++;
    	    mpp[s[j]-'a']++;
    	    while(dis>k){
    	        mpp[s[i]-'a']--;
    	        if(mpp[s[i]-'a']==0){
    	            dis--;
    	        }
    	        i++;
    	    }
    	    cnt+=j-i+1;
    	    j++;
    	}
    	return cnt;
    }
    long long int countSubstr (string s, int k) {
    	//code here.
    	return f(s,k)-f(s,k-1);
    }
};
