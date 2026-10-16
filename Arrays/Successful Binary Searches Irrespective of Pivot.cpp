class Solution {
  public:
    int countAlwaysFound(vector<int>& arr) {
        // code here
        int n = arr.size();
                if(n == 1) return 1;
                vector<int> dpL = arr, dpR = arr;
                for(int i = 1;i<n;i++){
                    dpL[i] = max(dpL[i], dpL[i-1]);
                    dpR[n-1-i] = min(dpR[n-1-i], dpR[n-i]);
                }
                int k = 0;
                for(int i = 0;i<arr.size();i++){
                    if(i>0 && i<n-1) {
                        if(arr[i] >= dpL[i-1] && arr[i] <= dpR[i+1]) k++;
                    } else if(i == 0 && arr[0] <= dpR[1]) k++;
                    else if(i == n-1 && arr.back() >= dpL[n-2]) k++;
                }
                return k;
    }
};
