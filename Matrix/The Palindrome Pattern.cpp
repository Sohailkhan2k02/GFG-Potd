//T.C : O(n*n)
//S.C : O(n)
class Solution {
  public:
    bool isPal(string &s){
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int n=arr.size();
        for(int i=0; i<n; i++){
            string row;
            for(int j=0; j<n; j++){
                row+=to_string(arr[i][j]);
            }
            if(isPal(row)){
                return to_string(i)+" R";
            }
        }
        
        for(int j=0; j<n; j++){
            string col;
            for(int i=0; i<n; i++){
                col+=to_string(arr[i][j]);
            }
            if(isPal(col)){
                return to_string(j)+" C";
            }
        }
        return "-1";
    }
};
