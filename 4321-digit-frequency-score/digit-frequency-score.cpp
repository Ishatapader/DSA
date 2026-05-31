class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> frequency(10, 0);
        int Mul = 0;
        if(n == 0){
            frequency[0]++;
        }
        while(n > 0) {
            int digit = n % 10;
            frequency[digit]++;
            n /= 10;
        }
        for (int i = 0; i < frequency.size(); i++) {
            Mul += frequency[i] * i;
        }
        return Mul;
    }
};