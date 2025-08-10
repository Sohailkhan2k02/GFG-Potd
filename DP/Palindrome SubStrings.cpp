class Solution {
    private:
    int getPallindrom(int i, int j, string &str){
        int count=0;
       while (i >= 0 && j < str.length()
        && str[i]==str[j]) {
      count++;
      i--;
      j++;
    }
        return count;
    }
  public:
    int countPS(string &s) {
        // code here
        int count=0;
        for (int i=0; i<s.length(); i++){
            //For  odd length
            count= count+getPallindrom(i, i, s);
            count= count+ getPallindrom(i, i+1, s);
            
            
        }
        //Do not count the sigle length Pallindrome
        return count-s.length();
    }
};
