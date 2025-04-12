
class Solution {
  public:
    int m, n;
    vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
    
    void dfs(vector<vector<int>>& image, int i, int j, int val,int currColor) {
        
        if(i < 0 || i >= m || j < 0 || j >= n || image[i][j] != currColor){
            return;
        }
        image[i][j] = val;
        
        for(auto& dir : directions){
            int x = i + dir[0];
            int y = j + dir[1];
            dfs(image,x,y,val,currColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        
        m = image.size();
        n = image[0].size();
        int currColor = image[sr][sc];
        if(currColor != newColor){
            dfs(image,sr,sc,newColor,currColor); 
        }
        return image;    }
};
