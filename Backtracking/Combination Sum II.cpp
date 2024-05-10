// T.C : O(2^N)
// S.C : O(N^2)
class Solution{
public:
    void f(int ind, vector<int>&arr, int n, int k, vector<int>&ds, vector<vector<int>>&res){
        if(k==0){
            res.push_back(ds);
            return;
        }
        
        for(int i=ind; i<n; i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(k-arr[i]>=0){
                ds.push_back(arr[i]);
                f(i+1,arr,n,k-arr[i],ds,res);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        sort(arr.begin(),arr.end());
        vector<int>ds;
        vector<vector<int>>res;
        f(0,arr,n,k,ds,res);
        return res;
    }
};
