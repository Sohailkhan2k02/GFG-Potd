//T.C : O(n*m)
//S.C : O(1)
class Solution {
  public:
     void reverse(vector<int>& arr, int start, int end){
        while (start < end)
        {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
     }
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        // code here
        int n=mat.size(),m=mat[0].size();
        k = k % m;
    
        for (int i = 0; i < n; i++) {
            reverse(mat[i], 0, k - 1);      
            reverse(mat[i], k, m - 1);      
            reverse(mat[i], 0, m - 1);     
        }
    
        return mat;
    }
};
