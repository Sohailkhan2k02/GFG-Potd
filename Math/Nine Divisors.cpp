class Solution {
  public:
    vector<int> sieve(int n){
        vector<bool> isPrime(n, true);
        vector<int> result;
        isPrime[0]=false;
        isPrime[1]=false;
        for(int i=2; i<n; i++){
            if(isPrime[i]){
                for(int j=i*i; j<n; j+=i){
                    isPrime[j]=false;
                }
            }
        }
        for(int i=0; i<n; i++){
            if(isPrime[i]){
                result.push_back(i);
            }
        }
        return result;
    }
    int countNumbers(int n) {
        // Code Here
        int count=0;
        vector<int> primes = sieve(sqrt(n)+1);
        for(int i=0; i<primes.size(); i++){
            if(pow(primes[i],8)<=n){
                count++;
            }else{
                break;
            }
        }
        for(int i=0; i<primes.size(); i++){
            for(int j=i+1; j<primes.size(); j++){
                if(pow(primes[i],2)*pow(primes[j],2)<=n){
                    count++;
                }else{
                    break;
                }
            }
        }
        return count;
    }
};
