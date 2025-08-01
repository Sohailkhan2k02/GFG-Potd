class Solution {
  public:
    int countBalanced(vector<string>& arr) {
        // code here
        auto getCount = [&] (string s) {
            int ans = 0;
            string txt = "aeiou";
            for(char c :s){
                if(txt.find(string(1,c)) != string::npos) ans++;
            }
            return ans;
        };
        int n = arr.size();
        vector<int>vc(n);
        for(int i = 0;i<n;i++){
            vc[i] = getCount(arr[i]);
            vc[i] -= (arr[i].length() - vc[i]);
        }
        int ans = 0;
        map<int,int>mp;
        mp[0] = 1;
        int sum = 0;
        for(int i = 0;i < n;i++){
            sum += vc[i];
            ans += mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};
