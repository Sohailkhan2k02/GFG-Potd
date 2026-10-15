class Solution {
  public:
    int maxValue(int n) {
        // code here
        int i=30;
                int ans=0;
                while(i>=0){
                    int first = (n>>i)&1;
                    int second = 0;
                    if((i-1)>0)
                    second=(n>>(i-1))&1;
                    int third = 0;
                    if((i-2)>=0)
                    third=(n>>(i-2))&1;

                    if(first==1&&second==1&&third==1){
                        ans+=1<<i;
                        ans+=1<<(i-1);
                        // make 111 -> 110
                        i-=3;
                    }
                    else if(first==1){
                        ans+=1<<i;
                        i--;
                    }
                    else{
                        i--;
                    }
                }
                return ans;
    }
};
