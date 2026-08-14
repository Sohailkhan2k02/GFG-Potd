class Solution {
public:
    bool isPossible(vector<int>& arr, int s, int x) {
        vector<long long> numbers;
        
        numbers.push_back(s);

        if (x == 0)
            return true;

        long long total = s;

        for (int i = 0; i < arr.size(); i++) {
            numbers.push_back(arr[i] + total);
            total += arr[i] + total;
        }

        for (int i = numbers.size() - 1; i >= 0; i--) {
            if (numbers[i] < x) {
                x -= numbers[i];
            }
            else if (numbers[i] == x) {
                return true;
            }
        }

        return false;
    }
};
