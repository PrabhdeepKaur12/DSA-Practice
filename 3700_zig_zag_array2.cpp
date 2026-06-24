class Solution {
public:
    static const int MOD = 1000000007;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(Matrix &a, Matrix &b) {
        int n = a.size();
        Matrix c(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (a[i][k] == 0) continue;
                for (int j = 0; j < n; j++) {
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }
        return c;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();
        Matrix result(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) result[i][i] = 1;

        while (exp > 0) {
            if (exp & 1) result = multiply(result, base);
            base = multiply(base, base);
            exp >>= 1;
        }

        return result;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1) return m;

        int size = 2 * m;

        vector<long long> state(size, 0);

        // length 2 state
        for (int x = 0; x < m; x++) {
            state[x] = x;              // up[x]
            state[m + x] = m - x - 1;  // down[x]
        }

        if (n == 2) {
            long long ans = 0;
            for (long long v : state) ans = (ans + v) % MOD;
            return ans;
        }

        Matrix trans(size, vector<long long>(size, 0));

        // newUp[x] = sum of down[y], where y < x
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < x; y++) {
                trans[x][m + y] = 1;
            }
        }

        // newDown[x] = sum of up[y], where y > x
        for (int x = 0; x < m; x++) {
            for (int y = x + 1; y < m; y++) {
                trans[m + x][y] = 1;
            }
        }

        Matrix finalTrans = power(trans, n - 2);

        long long ans = 0;

        for (int i = 0; i < size; i++) {
            long long val = 0;
            for (int j = 0; j < size; j++) {
                val = (val + finalTrans[i][j] * state[j]) % MOD;
            }
            ans = (ans + val) % MOD;
        }

        return ans;
    }
};