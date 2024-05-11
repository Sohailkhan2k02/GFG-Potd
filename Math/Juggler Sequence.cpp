//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    vector<int> jugglerSequence(int n) {
        // code here
        vector<int>v;
        v.push_back(n);
        while(n!=1){
            if(n%2==0){
                n=pow(n,0.5);
            }
            else{
                n=pow(n,1.5);
            }
            v.push_back(n);
        }
        return v;
    }
};
