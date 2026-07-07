class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0) { return 0; }
        int sum = 0;
        long long non_zero = 0;
        long long place = 1;

        while (n > 0) {
            int digit = n % 10;

            sum += digit;

            if (digit != 0) {
                non_zero = digit * place + non_zero;
                place *= 10;
            }
            n /= 10;
        }
        return non_zero * sum;
    }
};