//T.C : O(n)
//S.C : O(n)
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    vector<int>f2(int arr[], int n){
        vector<int>rft(n,0);
        rft[n-1]=arr[n-1];
        for(int i=n-2; i>=0; i--){
            rft[i]=max(rft[i+1],arr[i]);
        }
        return rft;
            
    }
    vector<int>f1(int arr[], int n){
        vector<int>lft(n,0);
        lft[0]=arr[0];
        for(int i=1; i<n; i++){
            lft[i]=max(lft[i-1],arr[i]);
        }
        return lft;
    }
    long long trappingWater(int arr[], int n){
        // code here
        vector<int>lft=f1(arr,n);
        vector<int>rft=f2(arr,n);
        long long cnt=0;
        for(int i=0; i<n; i++){
            cnt+=min(lft[i],rft[i])-arr[i];
        }
        return cnt;
        
    }
};
