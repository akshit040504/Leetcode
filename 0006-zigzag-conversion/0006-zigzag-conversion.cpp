class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s; // No zigzag needed for a single row.

        vector<string> rows(min(numRows, int(s.length())));
        int currentRow = 0;
        bool goingDown = false;

        // Traverse the string and assign characters to rows
        for (char c : s) {
            rows[currentRow] += c;
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown; // Change direction
            }
            currentRow += goingDown ? 1 : -1;
        }

        // Combine all rows to form the result
        string result;
        for (string row : rows) {
            result += row;
        }
        return result;
    }
};