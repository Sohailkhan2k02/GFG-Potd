
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
         int sum = 0;

    while (n > 0) {
        int x = log2(n); 
        sum += x * (1 << (x - 1)) + (n - (1 << x) + 1);
        n -= (1 << x); 
    }

    return sum;
    }
};
