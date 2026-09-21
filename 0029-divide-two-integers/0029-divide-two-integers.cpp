class Solution {
public:
    int divide(int dividend, int divisor) {

        // Special overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine the sign of the answer
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long to safely handle INT_MIN
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long quotient = 0;

        // Repeatedly subtract large powers of divisor
        while (a >= b) {

            long long value = b;
            long long multiple = 1;

            while (a >= (value << 1)) {
                value = value << 1;
                multiple = multiple << 1;
            }

            a -= value;
            quotient += multiple;
        }

        if (negative) {
            quotient = -quotient;
        }

        // 32-bit range check
        if (quotient > INT_MAX) {
            return INT_MAX;
        }

        if (quotient < INT_MIN) {
            return INT_MIN;
        }

        return (int)quotient;
    }
};