//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int sum=0;
        int maxi=0;
        int closestdiff=arr[0]+arr[1]+arr[2];
        for(int i=0; i<n; i++){
            int j=i+1,k=n-1;
            while(j<k){
                sum=arr[i]+arr[j]+arr[k];
                if(abs(target-sum)<abs(target-closestdiff)){
                    closestdiff=sum;
                }
                else if(abs(target-sum)==abs(target-closestdiff)){
                    closestdiff=max(closestdiff,sum);
                }
                
                if(sum<target){
                    j++;
                }
                else if(sum>target){
                    k--;
                }
                else return sum;
            }
        }
        return closestdiff;
    }
};
