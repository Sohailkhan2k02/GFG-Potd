class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        if(arr[0]!=5)return false;
        
        int n5 = 0;
        int n10 = 0;
    
        
        for(int i=0;i<arr.size();i++){
            
            if(arr[i]==5){
                n5++;
            }
            else if(arr[i]==10){
                if(n5==0)return 0;
                n5--;
                n10++;
            }
            else{
                if(n5==0)return 0;
                else if(n10!=0){
                    n5--;
                    n10--;
                }
                else if(n5<=2)return 0;
                else{
                    n5-=3;
                }
            }
        }
        
        return 1;
    }
};
