class Solution {
public:
    // Function to expand around a center
    int expand(string &s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;  // palindrome length
    }

    string longestPalindrome(string s) {
        if (s.length() == 0) return "";

        int start = 0, maxLen = 1;

        for (int i = 0; i < s.length(); i++) {
            // odd-length
            int len1 = expand(s, i, i);

            // even-length
            int len2 = expand(s, i, i + 1);

            int currLen = max(len1, len2);

            if (currLen > maxLen) {
                maxLen = currLen;
                start = i - (currLen - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};
