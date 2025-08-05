//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        int n = str.length();
     unordered_map<char, int>mpp;
    mpp['I']=1;
    mpp['V']=5;
    mpp['X']=10;
    mpp['L']=50;
    mpp['C']=100;
    mpp['D']=500;
    mpp['M']=1000;
    
    int result = 0;
    for(int i=0; i<n; i++){
        if(mpp[str[i]] < mpp[str[i+1]]){
            result = result - mpp[str[i]];
        }
        else{
            result+=mpp[str[i]];
        }
    }
    return result;

    }
};
