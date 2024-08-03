//T.C : O(n)
//S.C : O(n)
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
         stack<int> s;
        for(int j = 0; j < n; j++){
                s.push(j);
            }   
            
        int count = 0;
        while(count<n-1){
            int first = s.top();
                        s.pop();
            int second= s.top();
                        s.pop();
                        
            if(M[first][second]){
                s.push(second);
            }
            else s.push(first);
            count++;
        }
        if(s.empty()) return -1;
        
        int celebrity = s.top();

   
    for (int i = 0; i < n; i++) {
        if (i !=celebrity && (M[i][celebrity] == 0 || M[celebrity][i] != 0)) {
            return -1;
        }
    }

    return celebrity;
        
    }
};
