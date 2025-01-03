//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        unordered_map<int,int>mp;
        int xor1=0,count=0;
        for(int i=0;i<n;i++){
            xor1=xor1^arr[i];
            if(xor1==k)count++;
            int target=xor1^k;
            if(mp.find(target) != mp.end()){
                count+=mp[target];
            }
            mp[xor1]++;
        }
        return count;
    }
};
