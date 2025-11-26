class Solution {
  public:
    int andInRange(int l, int r) {
        // code here
        int ans = 0;
        for(int i = 31; i >= 0; i--){
            int a = (l >> i) & 1;
            int b = (r >> i ) & 1;
            if(a != b)
                break;
            if(a == 1)
                ans |= (1 << i);
        }
        return ans;
    }
};
