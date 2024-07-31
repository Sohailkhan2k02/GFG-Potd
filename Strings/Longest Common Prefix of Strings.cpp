//T.C : O(nlogn)
//S.C : O(1)
class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        string s=arr[0],t=arr[n-1];
        int i=0,j=0;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                i++,j++;
            }
            else break;
        }
        
        if(i==0) return "-1";
        return s.substr(0,i);
    }
};
