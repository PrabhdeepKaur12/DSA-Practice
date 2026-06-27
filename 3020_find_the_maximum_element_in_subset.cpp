class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums) freq[x]++;

        int ans = 1;

        // Special case: 1, 1, 1...
        if (freq.count(1)) {
            int c = freq[1];
            if (c % 2 == 0) c--;
            ans = max(ans, c);
        }

        for (auto &[start, cnt] : freq) {
            if (start == 1) continue;

            long long x = start;
            int len = 0;

            while (freq.count(x)) {
                // current x can be the middle element
                ans = max(ans, len + 1);

                // to continue, we need 2 copies of x
                if (freq[x] < 2) break;

                len += 2;

                if (x > 1000000000LL / x) break;
                x = x * x;
            }
        }

        return ans;
    }
};