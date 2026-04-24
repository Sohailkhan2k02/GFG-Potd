class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        int count=0;
        int maxheight=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]>=maxheight){
                count++;
                maxheight=arr[i];
            }
        }
        return count;
    }
};
