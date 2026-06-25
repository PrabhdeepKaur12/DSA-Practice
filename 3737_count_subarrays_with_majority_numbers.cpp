class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int offset = n + 2;
        int size = 2 * n + 5;

        vector<int> bit(size + 1, 0);

        auto update = [&](int idx) {
            while (idx <= size) {
                bit[idx]++;
                idx += idx & -idx;
            }
        };

        auto query = [&](int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & -idx;
            }
            return sum;
        };

        long long ans = 0;
        int prefix = 0;

        update(prefix + offset);

        for (int x : nums) {
            if (x == target) prefix++;
            else prefix--;

            ans += query(prefix + offset - 1);

            update(prefix + offset);
        }

        return ans;
    }
};