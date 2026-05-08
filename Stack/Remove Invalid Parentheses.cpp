class Solution {
  private:
    // Helper function to check if a string has valid parentheses
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') count--;
            if (count < 0) return false;
        }
        return count == 0;
    }

    // Depth-First Search with backtracking to find all valid combinations
    void dfs(string s, int start, int l_rem, int r_rem, set<string>& res) {
        // If no more removals are needed, check validity
        if (l_rem == 0 && r_rem == 0) {
            if (isValid(s)) {
                res.insert(s);
            }
            return;
        }

        for (int i = start; i < s.length(); i++) {
            // Pruning: Skip consecutive identical characters to avoid processing duplicates
            if (i != start && s[i] == s[i - 1]) continue;

            // Try removing an opening parenthesis
            if (s[i] == '(' && l_rem > 0) {
                dfs(s.substr(0, i) + s.substr(i + 1), i, l_rem - 1, r_rem, res);
            }
            // Try removing a closing parenthesis
            if (s[i] == ')' && r_rem > 0) {
                dfs(s.substr(0, i) + s.substr(i + 1), i, l_rem, r_rem - 1, res);
            }
        }
    }

public:
    vector<string> validParenthesis(string &s) {
        int l_rem = 0, r_rem = 0;

        // Step 1: Calculate the minimum number of '(' and ')' to remove
        for (char c : s) {
            if (c == '(') {
                l_rem++;
            } else if (c == ')') {
                if (l_rem > 0) {
                    l_rem--;
                } else {
                    r_rem++;
                }
            }
        }

        // Step 2: Use a set to store unique valid strings and sort them automatically
        set<string> valid_strings;
        dfs(s, 0, l_rem, r_rem, valid_strings);

        // Step 3: Handle the edge case where the result might be completely empty
        if (valid_strings.empty()) {
            return {""};
        }

        // Convert set to vector and return
        return vector<string>(valid_strings.begin(), valid_strings.end());
    }
};
