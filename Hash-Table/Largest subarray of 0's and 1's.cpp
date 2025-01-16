//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        unordered_map<int,int>mp;
        int sum=0;
        int maxlength=0;
        
        
        for (int i = 0; i < arr.size(); i++) 
        {
            if (arr[i] == 0) 
            {
                arr[i] = -1;
            }
        }
        
        mp[0]=-1;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            if (mp.find(sum) != mp.end()) 
            {
            maxlength=max(maxlength,i-mp[sum]);
            }
            
            else
            {
                mp[sum]=i;
            }
        }
        
        
        return maxlength;
    }
};
