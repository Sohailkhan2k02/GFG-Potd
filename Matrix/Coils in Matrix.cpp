class Solution {
  public:
    vector<vector<int>> rotate(int sz, vector<vector<int>> &matrix) {
        for (int i = 0; i < sz; i++) {
            int j = 0, k = sz - 1;
            while (j < k)
                swap(matrix[i][j++], matrix[i][k--]);
        }
        
        for (int j = 0; j < sz; j++) {
            int i = 0, k = sz - 1;
            while (i < k)
                swap(matrix[i++][j], matrix[k--][j]);
        }
        
        return matrix;
    }
    
    vector<int> generateSpiralSeq(int sz, vector<vector<int>> &matrix) {
        int top = 0, left = 0, right = sz - 1, bottom = sz - 1;
        vector<int> ans;
        
        while (top < bottom and left < right) {
            
            for (int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][left]);
            left++, right--;
            
            for (int i = left; i <= right; i++)
                ans.push_back(matrix[bottom][i]);
            bottom--, top++;
            
            for (int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][right]);
            right--, left++;
            
            for (int i = right; i >= left; i--)
                ans.push_back(matrix[top][i]);
            top++, bottom--;

        }
        
        return ans;
    }
    
  public:
    vector<vector<int>> formCoils(int n) {
        int sz = 4 * n, counter = 1;
        vector<vector<int>> matrix(sz, vector<int>(sz));
        
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++)
                matrix[i][j] = counter++;
        }
        
        vector<int> spiral1 = generateSpiralSeq(sz, matrix);
        vector<vector<int>> rotated = rotate(sz, matrix);

        vector<int> spiral2 = generateSpiralSeq(sz, rotated);
        
        return {spiral1, spiral2};
    }
};
