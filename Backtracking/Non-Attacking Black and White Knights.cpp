

//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int N, int M)
{
    // write code here
     int mod = 1e9+7;
    long long res=((long long)N*M-1)*N*M%mod;
    if(N>1 && M>2) res=(res-4*((long long)N-1)*(M-2)%mod)%mod;
    if(M>1 && N>2) res=(res-4*((long long)M-1)*(N-2)%mod)%mod;
    return res;
}
