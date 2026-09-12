class Solution {
  public:
    int maxProduct(vector<int> &arr, int K) {
        // code here
        sort(arr.begin(), arr.end());
        int ans = 1, i = 0, j = arr.size()-1, k = K;
        
        while(k)
        {
            // we can take 2 -ve if they are greater together else max positive
            if(k > 1 && i < j && (arr[i] * arr[i+1]) >= (arr[j-1] * arr[j]))
            {
                ans *= arr[i] * arr[i+1];
                i += 2;
                k -= 2;
            }
            else
            {
                ans *= arr[j--];
                k--;
            }
        }
        
        // if overall ans is negative we need min negative
        // as above strategy maximizes the answer
        if(ans < 0)
        {
            // sort by abs value
            sort(arr.begin(), arr.end(), [](int &a, int &b){
                return abs(a) < abs(b);
            });
            
            ans = 1, i = 0;
            while(K--)
                ans *= arr[i++];
        }
        
        return ans;
    }
};
