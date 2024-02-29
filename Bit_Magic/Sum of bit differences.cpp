//T.C : O(n*32)
//S.C : O(1)
class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
	    // code here
	    long long ans=0;
	    for(int i=0; i<32; i++){
	        long long cntOne=0,cntZer=0;
	        for(int j=0; j<n; j++){
	            if(arr[j]%2){
	                cntOne++;
	            }
	            else{
	                cntZer++;
	            }
	            
	            arr[j]=arr[j]/2;
	        }
	        
	        ans+=cntOne*cntZer*2;
	    }
	    return ans;
	}
};
