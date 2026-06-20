class Solution {
  public:
    int calculateModulo(string b, int MOD) {

		if (MOD == 2) {
			return (b.back() - '0') % 2;
		}
		if (MOD == 4) {

			int num = 0;

			if (b.size() == 1) {
				num = b.back() - '0';
			}
			else {
				num = (b[b.size() - 2] - '0') * 10 + (b.back() - '0');
			}

			return num % 4;
		}

		return 0;
	}

	int getLastDigit(string& a, string& b) {

		if (b == "0") {
			return 1;
		}

		int n = a.size();

		if (a[n - 1] == '0' || a[n - 1] == '1' ||
			a[n - 1] == '5' || a[n - 1] == '6') {

			return a[n - 1] - '0';
		}

		// Cyclicity
		// 2 -> 2 4 8 6
		// 3 -> 3 9 7 1
		// 4 -> 4 6
		// 7 -> 7 9 3 1
		// 8 -> 8 4 2 6
		// 9 -> 9 1

		vector<vector<int>> cyclicity =
		{
			{},
			{},
			{6, 2, 4, 8},
			{1, 3, 9, 7},
			{6, 4},
			{},
			{},
			{1, 7, 9, 3},
			{6, 8, 4, 2},
			{1, 9}
		};

		int num = a[n - 1] - '0';
		int cycleSize = cyclicity[num].size();

		int idx = calculateModulo(b, cycleSize);

		return cyclicity[num][idx];
	}
};
