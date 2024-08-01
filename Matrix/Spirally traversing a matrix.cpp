//T.C : O(n*m)
//S.C : O(n*m)
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        int n=mat.size(),m=mat[0].size();
        int left=0,right=m-1,top=0,bottom=n-1;
        vector<int>arr;
        while(left<=right && top<=bottom){
            for(int i=left; i<=right; i++){
                arr.push_back(mat[top][i]);
            }
            top++;
            
            for(int i=top; i<=bottom; i++){
                arr.push_back(mat[i][right]);
            }
            right--;
            
            if(top<=bottom){
                for(int i=right; i>=left; i--){
                    arr.push_back(mat[bottom][i]);
                }
                bottom--;
            }
            
            if(left<=right){
                for(int i=bottom; i>=top; i--){
                    arr.push_back(mat[i][left]);
                }
                left++;
            }
        }
        
        return arr;
    }
};
