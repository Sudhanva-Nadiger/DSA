class Solution {
    bool valid(vector<int>& A, int speed, double hour) {
        double time = 0;
        for (int i = 0; i < A.size(); ++i) {
            time = ceil(time);
            time +=  (double)A[i] / speed;
            if (time > hour) return false;
        }
        return true;
    }
public:
    int minSpeedOnTime(vector<int>& A, double hour) {
        if (hour < A.size() - 1) return -1;
        long L = 1, R = 1e7;
        while (L <= R) {
            long M = (L + R) / 2;
            if (valid(A, M, hour)) R = M - 1;
            else L = M + 1;
        }
        return L > 1e7 ? -1 : L;
    }
};