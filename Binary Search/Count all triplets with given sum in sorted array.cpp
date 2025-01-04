//T.C : O(n*logn)
//S.C : O(1)
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int ans = 0,n = arr.size();
        for(int i = 0;i<n-2;i++){
            int left = i+1,right = n-1;
            while(left<right){
                int sum = arr[i] + arr[left] + arr[right];
                if(sum<target) left++;
                else if(sum>target) right--;
                else{
                    int e1 = arr[left],e2 = arr[right],c1 = 0,c2 = 0;
                    while(left<=right && arr[left]==e1){
                        c1++;
                        left++;
                    }
                    while(left<=right && arr[right]==e2){
                    c2++;
                    right--;
                    }
                    if(e1 == e2) ans += (c1*(c1-1))/2;
                    else ans += c1*c2;
                }
            }
        }
        return ans;
    }
};
