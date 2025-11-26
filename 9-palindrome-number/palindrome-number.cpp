class Solution {
public:
    bool isPalindrome(int x) {
        // negative numbers can never be palindrome
        if (x < 0) return false;

        int original = x;
        int rev = 0;

        while (x > 0) {
            int digit = x % 10;
            x /= 10;

            // Check overflow (same logic as reverse integer problem)
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7))
                return false;

            rev = rev * 10 + digit;
        }

        return rev == original;
    }
};
