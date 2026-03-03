class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n = arr.size();
        if(n <= 2)
            return n;
        
        unordered_map<int, int> freq;    
        int left = 0, maxLen = 0;
        for(int right = 0; right < n; right++)
        {
            freq[arr[right]]++;
            
            while(freq.size() > 2)
            {
                freq[arr[left]]--;
                if(freq[arr[left]] == 0)
                {
                    freq.erase(arr[left]);
                }
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};
