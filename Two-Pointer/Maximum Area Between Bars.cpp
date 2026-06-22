class Solution {
  public:
    int maxArea(vector<int> &height) {
        // code here
        int n=height.size();
        int i=0, j=n-1;
        int maxi=0;

        while(i<j){
            maxi=max(maxi, min(height[i], height[j])*(j-i-1));
            if(height[i]<=height[j]) i++;
            else j--;
        }

        return maxi;
    }
};
