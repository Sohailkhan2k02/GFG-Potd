// Time Complexity -> O(n^3)
// Space Complexity -> O(1);
class Solution {
  public:
    string add(string num1, string num2){
       int n = num1.size(), m = num2.size();
       
       int carry = 0;
       int sum = 0;
       
       string ans;
       
       int i = n-1, j = m-1;
       
       while(i >= 0 or j >= 0 or carry)
       {
           int sum = 0;
           
           if(i >= 0)
            sum += (num1[i] - '0'); // char to number
           if(j >= 0)
            sum += (num2[j] - '0');
           if(carry)
            sum += carry;
           
           ans.push_back((sum%10) + '0'); // number to char
           carry = sum / 10;
           
           --i, --j;
       }
       
       reverse(ans.begin(), ans.end());
       
       return ans;
   }
   
    bool check(string num1, string num2, string str)
    {
        if(str.size() == 0)
            return true;
        
        string num3 = add(num1, num2);
        
        int lastIdx = min(int(num3.size()), (int) str.size());
        
        if(str.substr(0, lastIdx) == num3)
        {
            return check(num2, num3, str.substr(lastIdx));
        }
        
        return false;
    }
  
    bool isAdditiveSequence(string str) {
        // Your code here  
        int n = str.size();
        
        for(int i = 1; i < n-1; ++i)
        {
            string num1 = str.substr(0, i); // i length and not including ith
            
            for(int j = i+1; j < n; ++j)
            {
                string num2 = str.substr(i, j - i); // j-i length
                
                if(check(num1, num2, str.substr(j)))
                    return true;
            }
        }
        
        return false;
    }
};
