class Solution {
  public:
    bool findPattern(string& s) {
        // code here
int cnt = 0;
		for (const char&ch:s) {
			if (ch == 'x')cnt++;
			else if (ch == 'y') {
				if (cnt == 0)return false;
				cnt--;
			}
		}
		return cnt == 0;
    }
};
