// User function Template for C++

class Solution{
public:
    string matrixChainOrder(int p[], int n){
        vector<vector<pair<long long,int>>> dp(n, vector<pair<long long, int>> (n, {1e18, -1}));
        
        for(int i = 0; i < n - 1; i++){
            dp[i][i] = dp[i][i + 1] = {0, -1};
        }
        
        dp[n - 1][n - 1] = {0, -1};
        
        for(int i = n - 1; i > -1; i--){
            for(int j = i + 2; j < n; j++){
                for(int k = i + 1; k < j; k++){
                    long long cur = (long long)p[i] * (long long)p[j] * (long long)p[k] + dp[i][k].first + dp[k][j].first;
                    
                    if(cur < dp[i][j].first){
                        dp[i][j].first = cur;
                        dp[i][j].second = k;
                    }
                }
            }
        }
        
        vector<string> res(n + n - 1, "");
        char in;
        
        for(int i = 1, in = 'A'; i < n + n - 1; i += 2, in++)
            res[i] += in;
        
        function<void(int, int)> helper = [&](int i, int j) {
            if(j - i < 2)
                return;
            
            int start_pos = i * 2;
            int end_pos = j * 2;
            
            res[start_pos] += '(';
            res[end_pos] += ')';
            
            helper(i, dp[i][j].second);
            helper(dp[i][j].second, j);
        };
        
        helper(0, n - 1);
        
        string ans = "";
        
        for(auto i : res)
            ans += i;
        
        return ans;
    }
};
