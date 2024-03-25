//T.C : O(2^n)
//S.C : O(2^n*n)
class Solution{
public:	
    void generate(vector<string> &ans,int n, int ones, int zeros, string op){
        if(zeros > ones)
            return;
        if(op.length()==n){
            ans.push_back(op);
            return;
        }
         
        generate(ans, n, ones+1, zeros, op+'1');
        generate(ans, n, ones, zeros+1, op+'0');
    }
	vector<string> NBitBinary(int N)
	{
	    vector<string>ans;
        generate(ans, N, 0, 0, "");
        return ans;
    }
};
