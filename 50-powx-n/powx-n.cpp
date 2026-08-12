class Solution {
public:
    double myPow(double x, int n) {
        long long N = n; 
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double ans = 1.0;
        double cur_pro = x;
      
        while (N > 0) {
            if (N % 2 == 1) {
                ans *= cur_pro;
            }
            cur_pro *= cur_pro;
            N /= 2;
        }
        return ans;
    }
};