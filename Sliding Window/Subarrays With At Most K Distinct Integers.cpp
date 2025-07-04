//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int size=arr.size();
        unordered_map<int,int>mp;
        int i=0;
        int j=0;
        int ans=0;
        while(j<size){
            mp[arr[j]]++;
            while(mp.size()>k){
                mp[arr[i]]--;
                if(mp[arr[i]]==0){
                    mp.erase(arr[i]);
                }
                i+=1;
            }
            ans+=j-i+1;
            j++;
        }
        
        return ans;
    }
};
