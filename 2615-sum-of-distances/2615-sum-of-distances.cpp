class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;
        vector<long long> ans(n, 0);

        // Group indices by their values
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        // Calculate distances using prefix sums
        for (auto& [val, indices] : mp) {
            long long total = 0;

            for (int x : indices)
                total += x;

            long long prefix = 0;
            int m = indices.size();

            for (int j = 0; j < m; j++) {
                long long x = indices[j];

                long long left = j * x - prefix;

                long long right = (total - prefix - x)
                                - (m - j - 1) * x;

                ans[x] = left + right;

                prefix += x;
            }
        }

        return ans;
    }
};