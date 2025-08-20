class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = (n*m)-1;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            int midvalue =  mat[mid/m][mid%m];
            int lowvalue =  mat[low/m][low%m];
            int highvalue = mat[high/m][high%m];
            if(x == midvalue)
                return true;
            if(lowvalue <= midvalue)
            {
                // left part is sorted
                if(x >= lowvalue and x < midvalue)
                    high = mid - 1;
                else
                    low =  mid +  1;
            }
            else
            {
                if(x > midvalue and x <= highvalue)
                    low  = mid + 1;
                else
                    high = mid-1;
            }
        }
        return false;
    }
};
