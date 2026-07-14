class Solution {
  public:
    int find(vector<int>& arr) {
        // code here
        long long s = 1;
        long long e = *max_element(arr.begin(),arr.end());
        long long y = e;
        long long mid = s+(e-s)/2;
        long long ans = -1;
        //actually we've to prevent the overflow somehow.
        while(s <= e){
            long long x = mid;
            bool bl = false;
            bool bl1 = false;
            for(int i = 0;i<arr.size();i++){
                if(x <= arr[i]){
                    x = x - (arr[i]-x); 
                    if(x >= y){
                        bl = true;
                        break;
                    }
                    if(x <= 0){
                        bl1 = true;
                        break;
                    }
                }
                else{
                    x = x + (x - arr[i]);
                    if(x >= y){
                        bl = true;
                        break;
                    }
                    if(x <= 0){
                        bl1 = true;
                        break;
                    }
                }
            }
            if(bl1){
               s = mid + 1;
            }
            else if(bl){
               ans = mid;
               e = mid - 1;
            }
            else{
                if(x < 0){
                    s = mid + 1;
                }
                else{
                    ans = mid;
                    e = mid - 1;
                }
            }
            //forgot to write a condition.
            mid = s + (e-s)/2;
        }
        return (int)ans;
    }
};
