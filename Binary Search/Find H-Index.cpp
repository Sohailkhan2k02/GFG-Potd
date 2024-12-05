//T.C : O(n*logn)
//S.C : O(1)
class Solution {
  public:
    // Function to find hIndex
    bool f(int h, vector<int>&citations){
        int n=citations.size(),cnt=0;
        for(int i=0; i<n; i++){
            if(h<=citations[i]) cnt++;
            if(cnt>=h) return true;
        }
        return cnt>=h;
    }
    int hIndex(vector<int>& citations) {
        // code here
        int l=1,h=*max_element(citations.begin(),citations.end());
        int res=0;
        while(l<=h){
            int m=l+(h-l)/2;
            if(f(m,citations)){
                res=m;
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return res;
    }
};
