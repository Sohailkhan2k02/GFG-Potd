class Solution {
string fun( int n )
    {
        if( n == 1 ) return "1" ;
        string s = fun( n-1) ;
        string res = "";
        int i = 0 ;
        int j = 0 ;
        while( j < s.length() )
        {
            if( s[j] == s[i] )j++ ;
            else 
            {  
                res += to_string(j-i) ;
                res += s[i] ;
                i = j ;
            }
        }
        
        res +=  to_string(j-i) ;
        res +=  s[i] ;
        return res ;
    }
    
  public:
    string countAndSay(int n) {
       return fun( n ) ;
    }
};
