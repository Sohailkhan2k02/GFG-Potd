class Solution {
  public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        // code here
        int n=mat.size();
        int maxsum=INT_MIN;
        vector<vector<int>>presum=mat;
        
        for(int i=1;i<n;i++) {
            presum[i][0] += presum[i-1][0];
        }
        
        
        for(int j=1;j<n;j++) {
            presum[0][j] += presum[0][j-1];
        }
        
        for(int i=1;i<n;i++) {
            for(int j=1;j<n;j++) {
                int s=presum[i][j] + presum[i-1][j] + 
                    presum[i][j-1] - presum[i-1][j-1];
                presum[i][j] = s;
            }
        }
        
        
        for(int i=k-1;i<n;i++) {
            for(int j=k-1;j<n;j++) {
                int t=presum[i][j];
                int tosubtract=0;
                if(j-k >= 0) tosubtract += presum[i][j-k];
                if(i-k >= 0) tosubtract += presum[i-k][j];
                
                if(i-k>=0 && j-k>=0) tosubtract -= presum[i-k][j-k];
                
                maxsum=max(maxsum,t-tosubtract);
            }
        }
        
        return maxsum;
    }
};
