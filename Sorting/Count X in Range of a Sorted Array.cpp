class Solution {
  public:
    int firstOccurence(int num , vector<int>& arr , int start, int end){
        int low = start;
        int high = end;
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid] == num){
                ans = mid ;
                high = mid-1;
            } else if(arr[mid]< num){
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return ans;
        
    }
    int lastOccurence(int num , vector<int>& arr , int start, int end){
        int low = start;
        int high = end;
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid] == num){
                ans = mid ;
                low = mid+1;
            } else if(arr[mid]< num){
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return ans;
        
    }
    int getCnt(int num , vector<int>& arr, int start, int end){
        int fo = firstOccurence(num, arr,start,end);
        int lo = lastOccurence(num, arr, start, end);
        if(fo == -1 || lo == -1){
            return 0;
        }
        return (lo-fo+1);
    }
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        vector<int> ans;
        
        for(auto it: queries){
            ans.push_back(getCnt(it[2],arr,it[0],it[1]));
        }
        
        return ans;
    }
};
