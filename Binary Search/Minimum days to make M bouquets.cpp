class Solution {
  protected:
    bool checkThatTheyCanMakeOrNot(vector<int> arr, int k, int m, int day){
        int count=0;
        int bouquet=0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]<=day){
                count++;
                if(count==k){
                    count=0;
                    bouquet++;
                }
            }
            else{
                count=0;
            }
        }
        if(bouquet>=m)
        return true;
        else
        return false;
    }
  public:
    int minDaysBloom(vector<int>& arr, int k, int m) {
         if(m*k> arr.size())
         return -1;
         int low=*min_element(arr.begin(), arr.end());
         int high= *max_element(arr.begin(), arr.end());
         while(low<high){
             int mid= low+(high-low)/2;
             if(checkThatTheyCanMakeOrNot(arr, k, m, mid)){
                   high= mid;
             }
             else{
                
               low = mid + 1;
             }
         }
         return low;
    }
};
