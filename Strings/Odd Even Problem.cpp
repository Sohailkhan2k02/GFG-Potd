//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    string oddEven(string s) {
        // code here
        unordered_map<char,int>m;
        for(auto it:s){
            m[it]++;
        }
        int x = 0;
        int y = 0;
        for(auto it:m){
            int idx = (it.first-'a')+1;
            //cout<<idx<<endl;
            if(idx%2==0 && it.second%2==0){
                x++;
            }
            else if(idx%2!=0 && it.second%2!=0){
                y++;
            }
        }
        if((x+y)%2==0){
            return "EVEN";
        }
        return "ODD";
    }
};
