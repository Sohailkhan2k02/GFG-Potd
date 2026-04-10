// Function to find three numbers in the given array
// such that arr[smaller[i]] < arr[i] < arr[greater[i]]

class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n=arr.size();
        // vector<int>small(n,INT_MAX),large(n,-1);
        // small[0]=arr[0],large[n-1]=arr[n-1];
        // for(int i=1; i<n; i++){
        //     small[i]=min(arr[i],small[i-1]);
        //     large[n-i-1]=max(arr[n-i-1],large[n-i]);
        // }
        // // for(auto i:large) cout<<i<<" ";
        // for(int i=0; i<n; i++){
        //     if(arr[i]>small[i] && arr[i]<large[i]){
        //         return {small[i],arr[i],large[i]};
        //     }
        // }
        // return {};
        int a=INT_MAX,b=INT_MAX;
        for(int i=1; i<n; i++){
            if(arr[i]>b){
                return {a,b,arr[i]};
            }
            else if(arr[i]>a && arr[i]<b){
                b=arr[i];
            }
            else if(arr[i]>arr[i-1]){
                a=arr[i-1];
                b=arr[i];
            }
        }
        return {};
    }

};
