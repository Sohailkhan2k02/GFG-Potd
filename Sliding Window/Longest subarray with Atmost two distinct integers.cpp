//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n = arr.size();
        int i = 0;
        unordered_map<int, int> mp;
        int res = 0;
        int start = 0;
        while(i < n){
            mp[arr[i]]++;
            while(mp.size() > 2){
                mp[arr[start]]--;
                if(mp[arr[start]] == 0){
                    mp.erase(arr[start]);
                }
                start++;
            }
            res = max(res, i - start + 1);
            i++;
        }
        return res;
    }
};
