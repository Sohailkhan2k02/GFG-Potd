//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        int n=nums.size();
        int e1=0,e2=0;
        int c1=0,c2=0;
        for(int i=0; i<n; i++){
            if(nums[i]==e1){
                c1++;
            }
            else if(nums[i]==e2){
                c2++;
            }
            else if(c1==0){
                e1=nums[i];
                c1=1;
            }
            else if(c2==0){
                e2=nums[i];
                c2=1;
            }
            else c1--,c2--;
        }
        c1=0,c2=0;
        for(int i=0; i<n; i++){
            if(nums[i]==e1) c1++;
            if(nums[i]==e2) c2++;
        }
        vector<int>res;
        if(c1>n/3) res.push_back(e1);
        if(c2>n/3) res.push_back(e2);
        sort(res.begin(),res.end());
        if(!res.empty()){
            return res;
        }
        return {};
    }
};
