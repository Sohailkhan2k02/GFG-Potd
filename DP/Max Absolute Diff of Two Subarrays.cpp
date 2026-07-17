class Solution {
  public:
    int maxDiffSubArrays(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> v(n);
        int sum = 0;
        for(int i = n-1;i>=1;i--){
            sum += arr[i];
            v[i] = sum;
            if(sum < 0){
                sum = 0;
            }
        }
        vector<int> v1(n);
        sum = 0;
        for(int i = n-1;i>=1;i--){
            sum += arr[i];
            v1[i] = sum;
            if(sum > 0){
                sum = 0;
            }
        }
        vector<int> w(n);
        sum = 0;
        for(int i = 0;i<n-1;i++){
            sum += arr[i];
            w[i] = sum;
            if(sum < 0){
                sum = 0;
            }
        }
        
        vector<int> w1(n);
        sum = 0;
        for(int i = 0;i<n-1;i++){
            sum += arr[i];
            w1[i] = sum;
            if(sum > 0){
                sum = 0;
            }
        }
        int maxi = INT_MIN;
        for(int i = 0;i<n-1;i++){
            int a = w[i];
            int b = w1[i];
            int c = v[i+1];
            int d = v1[i+1];
            int e = max(abs(a-c),abs(a-d));
            a = max(abs(b-c),abs(b-d));
            maxi = max(maxi,max(e,a));
        }
        return maxi;
    }
};
