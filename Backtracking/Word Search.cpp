//T.C : O(n*m*4^sz)
//S.C : O(n*m)
class Solution {
  public:
    bool solve(int i,int j,int l,int n,int m,int sz,string &word,vector<vector<char>>& mat, vector<vector<bool>> &vis)
    {
        //Condition that defines we found word in the given matrix.
        if(l == sz) return 1;
        //Conditions to stop itterations.
        if(i<0 || j<0 || i == n || j == m || vis[i][j] || mat[i][j] != word[l]) return 0;
        //As we can visit only once to any box in an itteration we need to maintain visited array.
        vis[i][j] = 1;
        //Moving all 4 posible ways by keeping direction vectors and storing outcomes in res.
        bool res = 0;
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        for(int pos=0;pos<4;pos++)
        {
            res |= solve(i+dx[pos],j+dy[pos],l+1,n,m,sz,word,mat,vis);
        }
        // release the selected box.
        vis[i][j] = 0;
        //returns the result from current itteration
        return res;
    }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int sz = word.size();
        int n = mat.size(), m = mat[0].size();
        for(int i=0;i<n;i++)
        {
            vector<vector<bool>> vis(n,vector<bool>(m,0));
            for(int j=0;j<m;j++)
            {
                //if we found the word we get res from solution function as true.
                if(solve(i,j,0,n,m,sz,word,mat,vis)) 
                {
                    return true;
                }
            }
        }
        //word is not found.
        return false;
    }
};
