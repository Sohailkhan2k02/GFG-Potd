//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    // Returns count buildings that can see sunlight
    int countBuildings(vector<int> &height) {
        // code here
        int n=height.size();
        int maxi=height[0];
        int cnt=1;
        for(int i=1; i<n; i++){
            if(height[i]>maxi){
                cnt++;
                maxi=height[i];
            }
        }
        return cnt;
        
    }
};
