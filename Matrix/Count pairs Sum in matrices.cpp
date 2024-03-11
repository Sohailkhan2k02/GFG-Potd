// T.C: O(n^2)
// S.C: O(1)

//User function template for C++
class Solution{
public:	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    int count = 0;
	    int i=0,j=0;
	    int k=n-1,l=n-1;
	    while(i<n && k>=0){
	        int sum = mat1[i][j] + mat2[k][l];
	        if(sum==x){
	            count++;
	            l--;
	            j++;
	        }
	        else if(sum<x){
	            j++;
	        }
	        else{
	            l--;
	        }
	        if(j==n){
	            j=0;
	            i++;
	        }
	        if(l<0){
	            l=n-1;
	            k--;
	        }
	    }
	    
	    return count;
	}
};
