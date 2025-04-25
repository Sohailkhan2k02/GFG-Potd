//T.C : O(n)
//S.C : O(1)
// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& a) {
        // code here
        int cnt =0;
        int size=a.size();
        int el = a[0];
        for(int i=0; i<size; i++){
            if(cnt==0){
                cnt = 1;
                el = a[i];
            }
            
            else if(a[i]==el){
                cnt++;
            }
            
            else cnt--;
        }
        
        int cnt1=0;
        for(int i=0; i<size; i++){
            if(el == a[i])
            cnt1++;
        }
        
        if(cnt1>(size/2)){
            return el;
        }
        else
        return -1;
    }
};
