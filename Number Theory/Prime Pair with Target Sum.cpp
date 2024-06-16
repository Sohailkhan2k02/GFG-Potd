//T.C : O(n*loglog(n))
//S.C : O(1)
class Solution {
  public:
    vector<int> getPrimes(int n) {

        bool b[n + 1];
        memset(b, true, sizeof(b));

        b[0] = false;
        b[1] = false;

        vector<int> ptr;

        for (int i = 2; i <= sqrt(n); i++)
            for (int j = 2; i * j <= n; j++)
                b[i * j] = false;

        int flag = 0;

        for (int i = 2; i <= n; i++) {
            if (b[i] && b[n - i]) {
                ptr.push_back(i);
                ptr.push_back(n - i);
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            ptr.push_back(-1);
            ptr.push_back(-1);
        }
        return ptr;
    }
};
