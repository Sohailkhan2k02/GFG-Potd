
class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
    int low = 0, maxi = 0, startIdx = -1;
    multimap<int, int> mp;

    for (int i = 0; i < n; i++) {
        
        mp.insert({arr[i], i});

        int num1 = mp.begin()->first;  
        int num2 = prev(mp.end())->first;  

        while (num2 - num1 > x) {  
        
            int toErase = arr[low];
            auto it = mp.find(toErase);
            mp.erase(it);
            low++;  

            num1 = mp.begin()->first;  
            num2 = prev(mp.end())->first;  
        }

        int len = i - low + 1;
        
        if (len > maxi) {
            maxi = len;
            startIdx = low;
        }
        
        
    }

    vector<int> ans;
    
    if (startIdx != -1) {
        
        for (int i = startIdx; i < startIdx + maxi; i++) {
            ans.push_back(arr[i]);
        }
        
    }

    return ans;
    }
};
