//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    int i=0,j=0;
	    int sum=0,maxi=0;
	    unordered_map<int,int>mpp;
	    while(j<n){
	        sum+=arr[j];
	        int rem=(sum%k+k)%k;
	        if(rem==0){
	            maxi=max(maxi,j-i+1);
	        }
	        else if(mpp.find(rem)!=mpp.end()){
	            maxi=max(maxi,j-mpp[rem]);
	        }
	        else{
	            mpp[rem]=j;
	        }
	        j++;
	    }
	    return maxi;
	}
};
